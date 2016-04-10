/**********************************************************************
 *
 * sstDxf02Lib - sst dxf library
 * Hosted on github
 *
 * Copyright (C) 2016 Uli Rehr
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file gpl-2.0.txt included in the
 * packaging of this file.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * This copyright notice MUST APPEAR in all copies of the script!
 *
**********************************************************************/
// sstCsv2Dxf.cpp    11.03.16  Re.    11.03.16  Re.
//
// Tool converts csv table files together to a dxf drawing file.
// Merges layer csv file, block csv file, element arc csv file and so on ...
// Tool based on dxflib library.


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <rs_vector.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>

#include "sstCsv2Dxf.h"

//=============================================================================
int main(int argc, char** argv)
{
  sstCsv2DxfCls oCsv2Dxf;
  std::string oJobNam;
  std::string oDxfFilNam;
  int iStat = 0;

  // Open Protocol
  iStat = oCsv2Dxf.SST_PrtAuf ( 1, (char*) "Csv2Dxf");
  assert(iStat == 0);

  // Check given arguments:
  if (argc < 2)
  {
    // Write Message to Protocolfile and console
    iStat = oCsv2Dxf.SST_PrtWrtChar ( 1, (char*) "Csv2Dxf FileName.dxf", (char*) "Usage: ");

    // Close Protocol
    iStat = oCsv2Dxf.SST_PrtZu ( 1);
    return 0;
  }

  oDxfFilNam = argv[1];

  // create sst dxf database and set protocol channel
  sstDxf01DatabaseCls oSstDxfDB(&oCsv2Dxf);

  // read all csv file and import into sst dxf database
  iStat = oSstDxfDB.ReadAllCsvFiles(0,oDxfFilNam);
  if (iStat < 0)
  {
    // Write Message to Protocolfile and console
    iStat = oCsv2Dxf.SST_PrtWrtChar ( 1, (char*) "Error occured! Exit!", (char*) "Import: ");

    // Close Protocol
    iStat = oCsv2Dxf.SST_PrtZu ( 1);
    return 0;
  }

  // sstMisc01FilNamCls oFilNamConv;
    {
      sstDxf01WriteCls oDxfWrite(&oSstDxfDB);  // Open dxflib, set dxf export version and open dxf file
      oDxfWrite.WrtSecHeader(0);
      oDxfWrite.WrtSecTypes(0);
      oDxfWrite.WrtSecLayers(0);
      oDxfWrite.WrtSecStyles(0);
      oDxfWrite.WrtSecBlocks(0);
      oDxfWrite.WrtSecEntities(0);
      oDxfWrite.WrtSecObjects(0);
    }

    // Open DXF file
    DL_Dxf* dxf;
    DL_WriterA* dw;
    // RS_Vector dPnt2[4];
    // RS_Vector dPnt2WC[4];

    // Open Dxf-File for writing, using dxflib functions
    iStat = sstdxf_FileOpen ( 0, &dxf, &dw);

    // Write section HEADER to dxf file
    iStat = sstdxf_WrtSecHeader ( 0, &dxf, &dw);

    // Write Section Layers, Table Types (LINETYPES etc.)  to DXF file
    iStat = sstdxf_WrtSecTypes ( 0, &dxf, &dw);

    // Write Section Layers, Table LAYER to Dxf file
    iStat = sstdxf_WrtSecLayers ( 0, &dxf, &dw);

    // Write Section TABLES to Dxf file
    iStat = sstdxf_WrtSecStyles( 0, &dxf, &dw);

    // Section blocks
    dw->sectionBlocks();

    dxf->writeBlock(*dw,
                   DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Model_Space");

    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space");

    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space0");

    // Write one Symobl definition ================================================

    dxf->writeBlock(*dw,
                   DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));
    // ...
    // write block entities e.g. with dxf->writeLine(), ..

    dxf->writeLine(
        *dw,
        DL_LineData(0.0,   // start point
                    0.0,
                    0.0,
                    1.0,   // end point
                    1.0,
                    0.0),
        DL_Attributes("myblock1", 256, -1, "BYBLOCK"));

    dxf->writeLine(
        *dw,
        DL_LineData(0.0,   // start point
                    1.0,
                    0.0,
                    1.0,   // end point
                    0.0,
                    0.0),
        DL_Attributes("myblock1", 256, -1, "BYBLOCK"));

    // ...
    dxf->writeEndBlock(*dw, "myblock1");
    // End Symobl definition ================================================

    dxf->writeBlock(*dw,
                   DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));
    // ...
    // write block entities e.g. with dxf->writeLine(), ..
    // ...
    dxf->writeEndBlock(*dw, "myblock2");

    dw->sectionEnd();

    dw->sectionEntities();

    //===========================================================================

    dw->sectionEnd();
    dxf->writeObjects(*dw);
    dxf->writeObjectsEnd(*dw);
    dw->dxfEOF();
    dw->close();
    delete dw;
    delete dxf;

    // Close Protocol
    iStat = oCsv2Dxf.SST_PrtZu ( 1);
  return 0;
}
//=============================================================================
sstCsv2DxfCls::sstCsv2DxfCls()
{

}
//=============================================================================
