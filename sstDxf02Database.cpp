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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <rs_vector.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>

// #include "sstCsv2Dxf.h"

//=============================================================================
sstDxf02DatabaseCls::sstDxf02DatabaseCls(sstMisc01PrtFilCls *oTmpPrt)
{
  this->oPrt = oTmpPrt;
}
//=============================================================================
int sstDxf02DatabaseCls::ReadAllCsvFiles(int iKey, std::string oDxfFilNam)
{
  int iStat = 0;
  sstMisc01FilNamCls oFilNamConv;
  std::string oJobNam;

  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // remove given ending from filename
  iStat = oFilNamConv.RemoveExtension(0, "dxf", oDxfFilNam, &oJobNam);

  std::string oFilNamLayer;
  std::string oFilNamBlock;
  std::string oFilNamArc;
  std::string oFilNamInsert;
  std::string oFilNamMain;

  oFilNamLayer = oJobNam + "_Layer.csv";
  oFilNamBlock = oJobNam + "_Block.csv";
  oFilNamArc = oJobNam + "_Arc.csv";
  oFilNamInsert = oJobNam + "_Insert.csv";
  oFilNamMain = oJobNam + "_Main.csv";


  // Read whole main csv file into sst_rec_mem
  iStat = this->oSstFncMain.ReadCsvFile ( 0, oFilNamMain);
  // Check given arguments:
  if (iStat != 0)
  {
    // Write Message to Protocolfile and console
    // iStat = oCsv2Dxf.SST_PrtWrtChar ( 1, (char*) oFilNamLayer.c_str(), (char*) "File not found: ");
    iStat = this->oPrt->SST_PrtWrtChar ( 1, (char*) oFilNamMain.c_str(), (char*) "File not found: ");

    // Close Protocol
    // iStat = oCsv2Dxf.SST_PrtZu ( 1);
    return -2;
  }

  // Read whole layer csv file into sst_rec_mem
  iStat = this->oSstFncLay.ReadCsvFile ( 0, oFilNamLayer);
  // Check given arguments:
  if (iStat != 0)
  {
    // Write Message to Protocolfile and console
    // iStat = oCsv2Dxf.SST_PrtWrtChar ( 1, (char*) oFilNamLayer.c_str(), (char*) "File not found: ");
    iStat = this->oPrt->SST_PrtWrtChar ( 1, (char*) oFilNamLayer.c_str(), (char*) "File not found: ");

    // Close Protocol
    // iStat = oCsv2Dxf.SST_PrtZu ( 1);
    return -2;
  }

  // Read whole block csv file into sst_rec_mem
  iStat = oSstFncBlk.ReadCsvFile ( 0, oFilNamBlock);
  if (iStat != 0)
  {
    // Write Message to Protocolfile and console
    // iStat = oCsv2Dxf.SST_PrtWrtChar ( 1, (char*) oFilNamBlock.c_str(), (char*) "File not found: ");
    iStat = this->oPrt->SST_PrtWrtChar ( 1, (char*) oFilNamBlock.c_str(), (char*) "File not found: ");
  }

  // Read whole insert csv file into sst_rec_mem
  iStat = oSstFncInsert.ReadCsvFile ( 0, oFilNamInsert);

  // Read whole arc csv file into sst_rec_mem
  iStat = oSstFncArc.ReadCsvFile ( 0, oFilNamArc);

  return 0;
}
//=============================================================================
sstDxf02FncLayCls* sstDxf02DatabaseCls::getSstFncLay()
{
  return &this->oSstFncLay;
}
//=============================================================================
//void sstDxf02DatabaseCls::setSstFncLay(const sstDxf02FncLayCls &value)
//{
//  oSstFncLay = value;
//}
//=============================================================================
sstDxf02FncBlkCls* sstDxf02DatabaseCls::getSstFncBlk()
{
  return &this->oSstFncBlk;
}
//=============================================================================
//void sstDxf02DatabaseCls::setSstFncBlk(const sstDxf02FncBlkCls &value)
//{
//  oSstFncBlk = value;
//}
//=============================================================================
sstDxf02FncArcCls* sstDxf02DatabaseCls::getSstFncArc()
{
  return &this->oSstFncArc;
}
//=============================================================================
//void sstDxf02DatabaseCls::setSstFncArc(const sstDxf02FncArcCls &value)
//{
//  oSstFncArc = value;
//}
//=============================================================================
sstDxf02FncInsertCls* sstDxf02DatabaseCls::getSstFncInsert()
{
  return &this->oSstFncInsert;
}
//=============================================================================
//void sstDxf02DatabaseCls::setSstFncInsert(const sstDxf02FncInsertCls &value)
//{
//  oSstFncInsert = value;
//}
//=============================================================================
sstDxf02FncMainCls* sstDxf02DatabaseCls::getSstFncMain()
{
  return &this->oSstFncMain;
}
//=============================================================================
