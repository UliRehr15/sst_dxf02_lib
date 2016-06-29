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
// sstDxf02Layer.cpp   26.02.16  Re.   26.02.16  Re.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>
#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <rs_vector.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>

//=============================================================================
sstDxf02TypLayCls::sstDxf02TypLayCls()
{
  this->ulLayerID = 0;
  memset(this->Nam,0,dSSTDXFLAYERNAMELEN);
  this->flags = 0;
}
//=============================================================================
int sstDxf02TypLayCls::getFlags() const
{
  return flags;
}
//=============================================================================
void sstDxf02TypLayCls::setFlags(int value)
{
  flags = value;
}
//=============================================================================
char* sstDxf02TypLayCls::getName()
{
  return this->Nam;
}
//=============================================================================
void sstDxf02TypLayCls::setName(const char* cTmpName)
{
  strncpy(this->Nam,cTmpName,dSSTDXFLAYERNAMELEN);
}
//=============================================================================
unsigned long sstDxf02TypLayCls::getLayerID() const
{
return ulLayerID;
}
//=============================================================================
void sstDxf02TypLayCls::setLayerID(unsigned long value)
{
ulLayerID = value;
}
//=============================================================================
int sstDxf02TypLayCls::getSizeName() const
{
  return sizeof(this->Nam);
}
//=============================================================================
void sstDxf02TypLayCls::ReadFromDL(const DL_LayerData oDlLay)
{
  strncpy(this->Nam, oDlLay.name.c_str(),dSSTDXFLAYERNAMELEN);
  this->flags  = oDlLay.flags;
}
//=============================================================================
void sstDxf02TypLayCls::WritToDL(DL_LayerData *poDlLay)
{
    poDlLay->name = this->getName();
    poDlLay->flags = this->getFlags();
}
//=============================================================================
// Constructor
sstDxf02FncLayCls::sstDxf02FncLayCls():sstDxf02FncBaseCls(sizeof(sstDxf02TypLayCls))
{
  sstDxf02TypLayCls oLayRec;
  // Init new name Tree sorting object for Layer RecMem object
  int iStat = this->TreIni( 0, &oLayRec, oLayRec.getName(), oLayRec.getSizeName(), sstRecTyp_CC, &this->oLayerTree);
  assert(iStat == 0);
}
//=============================================================================
int sstDxf02FncLayCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *oCsvStr, sstDxf02TypLayCls *oTypLay)
{
  unsigned long ulTmpLayerID = 0;
  std::string oTmpStr;
  int iTmpFlags = 0;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, oCsvStr, &ulTmpLayerID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Str( 0, oCsvStr, &oTmpStr);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, oCsvStr, &iTmpFlags);

  if (iStat >= 0)
  {
    oTypLay->setLayerID(ulTmpLayerID);
    oTypLay->setName(oTmpStr.c_str());
    oTypLay->setFlags(iTmpFlags);

    // read base dxf attributes from csv string
    if (iStat >= 0)
      iStat = this->Csv_BaseRead2(0, sErrTxt, oCsvStr, oTypLay);

  }
  else
  {
    *sErrTxt = oCsvRow.GetErrorString();
  }

  return iStat;
}

// Csv Write Function
int sstDxf02FncLayCls::Csv_Write(int iKey, sstDxf02TypLayCls *poSstLAY, std::string *ssstDxfLib_Str)
{
  // sstStr01Cls oCsvRow;  // Csv String Convert object
  int iStat = 0;

  //  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstLAY->getLayerID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String( 0, poSstLAY->getName(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstLAY->getFlags(), ssstDxfLib_Str);

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite2 ( 0, *poSstLAY, ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

//  Bloc Function Write End
  return iStat;
}
//=============================================================================
int sstDxf02FncLayCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  char Nam[dSSTDXFLAYERNAMELEN]; /**< Layer Name */
//  int flags;               /**< Layer flags. (1 = frozen, 2 = frozen by default, 4 = locked) */

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "LayerID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "name";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "flags";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // append base attributes to layer csv titel row
  this->Csv_BaseHeader2(0,ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
sstRec04TreeKeyCls* sstDxf02FncLayCls::getNameSortKey()
{
  return &this->oLayerTree;
}
//=============================================================================
int sstDxf02FncLayCls::ReadCsvFile(int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oCsvFilLayer;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCsvFilLayer.fopenRd(0,oFilNam.c_str());
  // assert(iStat==0);
  if (iStat < 0) return -2;

  // sstDxf02FncLayCls oSstFncLay;  // layer recmem object
  std::string oLayStr;
  std::string oErrStr;
  dREC04RECNUMTYP dRecNo = 0;
  int iStat1 = 0;
  // Read title row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  if (iStat < 0) return -3;

  // Read first data row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);

  while (iStat1 >= 0)
  {
    sstDxf02TypLayCls oSstLay;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstLay);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstLay,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf02FncLayCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Layer data to Csv file
  oCsvFilNam = oDxfFilNam + "_Layer.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf02TypLayCls oDxfLay;
    iStat = this->Read(0,kk,&oDxfLay);

    oDxfLay.setLayerID(kk);

    this->Csv_Write( 0, &oDxfLay, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
