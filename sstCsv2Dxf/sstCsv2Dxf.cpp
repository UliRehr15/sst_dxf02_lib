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
#include <rs.h>

#include "sstCsv2Dxf.h"

//=============================================================================
int main(int argc, char** argv)
{
  sstCsv2DxfCls oCsv2Dxf;
  std::string oJobNam;
  std::string oDxfFilNam;
  int iStat = 0;

  // converts enum to string <BR>
  std::string oTypeString;
  RS2::EntityType eTypeEnum = RS2::EntityUnknown;
  sstDxf02EntityTypeCls oEntityType;

  oTypeString = oEntityType.Enum2String(eTypeEnum);
  oTypeString = "XXX";
  eTypeEnum = oEntityType.String2Enum(oTypeString);

  sstDxf02FncMainCls oMainFnc;  // functions for dxf main record
  std::string oMainCsvString;

  {
    sstDxf02TypMainCls oMainRec;  // dxf main record
    oMainRec.setMainID(22);
    oMainRec.setEntityType(RS2::EntityArc);
    oMainRec.setLayBlockID(44);
    oMainRec.setSectString("B");
    oMainRec.setTypeID(55);
    oMainFnc.Csv_Write(0,&oMainRec,&oMainCsvString);
    iStat = oMainCsvString.compare("22;\"B\";44;\"Arc\";55");
    assert(iStat == 0);
  }

  {
    sstDxf02TypMainCls oMainRec;  // dxf main record
    std::string oErrStr;
    iStat = oMainFnc.Csv_Read(0,&oErrStr,&oMainCsvString,&oMainRec);
    assert (iStat == 0);
    assert ( oMainRec.getMainID() == 22);
    assert ( oMainRec.getEntityType() == RS2::EntityArc);
    assert ( oMainRec.getLayBlockID() == 44);
    assert ( oMainRec.getSectString() == "B");
    assert ( oMainRec.getTypeID() == 55);
  }


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
  // sstDxf01DatabaseCls oSstDxfDB(&oCsv2Dxf);

//  // read all csv file and import into sst dxf database
//  iStat = oSstDxfDB.ReadAllCsvFiles(0,oDxfFilNam);
  //  if (iStat < 0)
  //  {
  //    // Write Message to Protocolfile and console
  //    iStat = oCsv2Dxf.SST_PrtWrtChar ( 1, (char*) "Error occured! Exit!", (char*) "Import: ");

  //    // Close Protocol
  //    iStat = oCsv2Dxf.SST_PrtZu ( 1);
  //    return 0;
  //  }

  // sstMisc01FilNamCls oFilNamConv;
    // {
  sstDxf02WriteCls oDxfWrite(&oCsv2Dxf);  // Open dxflib, set dxf export version and open dxf file

  oDxfWrite.SetDxfFilNam( oDxfFilNam);
  iStat = oDxfWrite.ReadAllCsvFiles(0);  // import all csv data into sstdxf database
  if (iStat < 0)
  {
    // Write Message to Protocolfile and console
    iStat = oCsv2Dxf.SST_PrtWrtChar ( 1, (char*) "Error occured! Exit!", (char*) "Import: ");

    // Close Protocol
    iStat = oCsv2Dxf.SST_PrtZu ( 1);
    return 0;
  }
  if (iStat >= 0) iStat = oDxfWrite.OpenNewDxfFile(0,oDxfFilNam);  // Open dxf file for writing data
  if (iStat >= 0) iStat = oDxfWrite.WrtSecHeader(0);    // write header section to dxf file
  if (iStat >= 0) iStat = oDxfWrite.WrtSecTypes(0);     // write types section to dxf file
  if (iStat >= 0) iStat = oDxfWrite.WrtSecLayers(0);    // write layer section to dxf file
  if (iStat >= 0) iStat = oDxfWrite.WrtSecStyles(0);    // write styles section to dxf file
  if (iStat >= 0) iStat = oDxfWrite.WrtSecBlocks(0);    // write blocks section to dxf file
  if (iStat >= 0) iStat = oDxfWrite.WrtSecEntities(0);  // write entities section to dxf file
  if (iStat >= 0) iStat = oDxfWrite.WrtSecObjects(0);   // write objects section to dxf file

    // Close Protocol
  iStat = oCsv2Dxf.SST_PrtZu ( 1);
  return 0;
}
//=============================================================================
sstCsv2DxfCls::sstCsv2DxfCls()
{

}
//=============================================================================
