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

#include "sstCsv2Dxf.h"

//=============================================================================
sstDxf01DatabaseCls::sstDxf01DatabaseCls(sstMisc01PrtFilCls *oTmpPrt)
{
  this->oPrt = oTmpPrt;
}
//=============================================================================
int sstDxf01DatabaseCls::ReadAllCsvFiles(int iKey, std::string oDxfFilNam)
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

  oFilNamLayer = oJobNam + "_Layer.csv";
  oFilNamBlock = oJobNam + "_Block.csv";
  oFilNamArc = oJobNam + "_Arc.csv";
  oFilNamInsert = oJobNam + "_Insert.csv";


  // Read whole layer csv file into sst_rec_mem
  iStat = oSstFncLay.ReadCsvFile ( 0, oFilNamLayer);
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
sstDxf01FncLayCls* sstDxf01DatabaseCls::getSstFncLay()
{
  return &this->oSstFncLay;
}
//=============================================================================
void sstDxf01DatabaseCls::setSstFncLay(const sstDxf01FncLayCls &value)
{
  oSstFncLay = value;
}
//=============================================================================
sstDxf01FncBlkCls* sstDxf01DatabaseCls::getSstFncBlk()
{
  return &this->oSstFncBlk;
}
//=============================================================================
void sstDxf01DatabaseCls::setSstFncBlk(const sstDxf01FncBlkCls &value)
{
  oSstFncBlk = value;
}
//=============================================================================
sstDxf01FncArcCls* sstDxf01DatabaseCls::getSstFncArc()
{
  return &this->oSstFncArc;
}
//=============================================================================
void sstDxf01DatabaseCls::setSstFncArc(const sstDxf01FncArcCls &value)
{
  oSstFncArc = value;
}
//=============================================================================
sstDxf01FncInsertCls* sstDxf01DatabaseCls::getSstFncInsert()
{
  return &this->oSstFncInsert;
}
//=============================================================================
void sstDxf01DatabaseCls::setSstFncInsert(const sstDxf01FncInsertCls &value)
{
  oSstFncInsert = value;
}
//=============================================================================
