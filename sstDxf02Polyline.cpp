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
//  sstDxf02Polyline.cpp   29.04.16  Re.   29.04.16  Re.
//
//  Functions for sst Dxf Polyline Classes
//

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
// Constructor
sstDxf02TypPolylineCls::sstDxf02TypPolylineCls()
{
  this->flags = 0;
  this->m = 0;
  this->n = 0;
  this->number = 0;
}
//=============================================================================
// Set Test Data
int sstDxf02TypPolylineCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  return 0;
}
//=============================================================================
void sstDxf02TypPolylineCls::ReadFromDL(const DL_PolylineData oDLPolyline)
{
  this->flags = oDLPolyline.flags;
  this->m = oDLPolyline.m;
  this->n = oDLPolyline.n;
  this->number = oDLPolyline.number;
}
//=============================================================================
void sstDxf02TypPolylineCls::WritToDL(DL_PolylineData *poDLPolyline)
{
  poDLPolyline->flags = this->flags;
  poDLPolyline->m = this->m;
  poDLPolyline->n = this->n;
  poDLPolyline->number = this->number;
}
//=============================================================================
unsigned int sstDxf02TypPolylineCls::getNumber() const
{
return number;
}
//=============================================================================
void sstDxf02TypPolylineCls::setNumber(unsigned int value)
{
number = value;
}
//=============================================================================
unsigned int sstDxf02TypPolylineCls::getM() const
{
return m;
}
//=============================================================================
void sstDxf02TypPolylineCls::setM(unsigned int value)
{
m = value;
}
//=============================================================================
unsigned int sstDxf02TypPolylineCls::getN() const
{
return n;
}
//=============================================================================
void sstDxf02TypPolylineCls::setN(unsigned int value)
{
n = value;
}
//=============================================================================
int sstDxf02TypPolylineCls::getFlags() const
{
return flags;
}
//=============================================================================
void sstDxf02TypPolylineCls::setFlags(int value)
{
flags = value;
}
//=============================================================================
// Constructor
sstDxf02FncPolylineCls::sstDxf02FncPolylineCls():sstDxf02FncBaseCls(sizeof(sstDxf02TypPolylineCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf02TypPolylineCls));
}
//=============================================================================
// Csv Read Function
int sstDxf02FncPolylineCls::Csv_Read(int iKey, std::string *oErrStr, std::string *ssstDxfLib_Str, sstDxf02TypPolylineCls *osstDxf02TypPolylineCls)
{
  dREC04RECNUMTYP dLocPLineID = 0;
  unsigned int uiLocNumber;
  unsigned int uiLocM;
  unsigned int uiLocN;
  int iLocFlags;

  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  //  unsigned int number;
  //  unsigned int m;
  //  unsigned int n;
  //  int flags;

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocPLineID);
  if (iStat >= 0) osstDxf02TypPolylineCls->setRecordID(dLocPLineID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt2( 0, ssstDxfLib_Str, &uiLocNumber);
  if (iStat >= 0) osstDxf02TypPolylineCls->setNumber(uiLocNumber);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt2( 0, ssstDxfLib_Str, &uiLocM);
  if (iStat >= 0) osstDxf02TypPolylineCls->setM(uiLocM);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt2( 0, ssstDxfLib_Str, &uiLocN);
  if (iStat >= 0) osstDxf02TypPolylineCls->setN(uiLocN);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocFlags);
  if (iStat >= 0) osstDxf02TypPolylineCls->setFlags(iLocFlags);

  // read base dxf attributes from csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseRead(0, oErrStr, ssstDxfLib_Str, osstDxf02TypPolylineCls);

  *oErrStr = oCsvRow.GetErrorString();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

//  Bloc Function1 End
  return iStat;
}
//=============================================================================
// Csv Write Function
int sstDxf02FncPolylineCls::Csv_Write(int iKey, sstDxf02TypPolylineCls *poSstPolyline, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstPolyline->getRecordID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, poSstPolyline->getNumber(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, poSstPolyline->getM(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_UInt2_2String( 0, poSstPolyline->getN(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Int2_2String( 0, poSstPolyline->getFlags(), ssstDxfLib_Str);

  //  unsigned int number;
  //  unsigned int m;
  //  unsigned int n;
  //  int flags;

  // write base dxf attributes to csv string
  if (iStat >= 0)
    iStat = this->Csv_BaseWrite ( 0, *poSstPolyline, ssstDxfLib_Str);


  return iStat;
}
//=============================================================================
int sstDxf02FncPolylineCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  //  unsigned int number;
  //  unsigned int m;
  //  unsigned int n;
  //  int flags;

  oTitelStr = "PolylineID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Number";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "M";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "N";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "Flags";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // append base attributes to polyline csv titel row
  this->Csv_BaseHeader(0,ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
int sstDxf02FncPolylineCls::ReadCsvFile(int iKey, std::string oFilNam)
{
  sstMisc01AscFilCls oCsvFilLayer;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCsvFilLayer.fopenRd(0,oFilNam.c_str());
  if (iStat < 0) return -2;

  std::string oLayStr;
  std::string oErrStr;
  dREC04RECNUMTYP dRecNo = 0;
  int iStat1 = 0;
  // Read title row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  if (iStat1 < 0) return -3;

  // Read first data row
  iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  while (iStat1 >= 0)
  {
    sstDxf02TypPolylineCls oSstArc;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstArc);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstArc,&dRecNo);
    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstDxf02FncPolylineCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Insert to Csv file
  oCsvFilNam = oDxfFilNam + "_Polyline.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf02TypPolylineCls oDxfPolyline;
    iStat = this->Read(0,kk,&oDxfPolyline);

    oDxfPolyline.setRecordID(kk);

    this->Csv_Write( 0, &oDxfPolyline, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
