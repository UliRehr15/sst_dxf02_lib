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
//  sstDxf02HatchLoop.cpp   29.04.16  Re.   29.04.16  Re.
//
//  Functions for sst Dxf Hatch Loop Classes
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
sstDxf02TypHatchLoopCls::sstDxf02TypHatchLoopCls()
{
  this->dRecordID = 0;
  this->numEdges = 0;
}
//=============================================================================
// Set Test Data
int sstDxf02TypHatchLoopCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  this->dRecordID = 5;
  this->numEdges = 1;
  return 0;
}
//=============================================================================
void sstDxf02TypHatchLoopCls::ReadFromDL(const DL_HatchLoopData oDLHatchLoop)
{
  this->numEdges = oDLHatchLoop.numEdges;
}
//=============================================================================
void sstDxf02TypHatchLoopCls::WritToDL(DL_HatchLoopData *poDLHatchLoop)
{
  poDLHatchLoop->numEdges = this->numEdges;
}
//=============================================================================
dREC04RECNUMTYP sstDxf02TypHatchLoopCls::getRecordID() const
{
return dRecordID;
}
//=============================================================================
void sstDxf02TypHatchLoopCls::setRecordID(const dREC04RECNUMTYP &value)
{
dRecordID = value;
}
//=============================================================================
int sstDxf02TypHatchLoopCls::getNumEdges() const
{
return numEdges;
}
//=============================================================================
void sstDxf02TypHatchLoopCls::setNumEdges(int value)
{
numEdges = value;
}
//=============================================================================
// Constructor
sstDxf02FncHatchLoopCls::sstDxf02FncHatchLoopCls():sstDxf02FncBaseCls(sizeof(sstDxf02TypHatchLoopCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf02TypHatchLoopCls));
}
//=============================================================================
// Csv Read Function
int sstDxf02FncHatchLoopCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf02TypHatchLoopCls *osstDxf02TypHatchLoop)
{
  dREC04RECNUMTYP dLocRecordID = 0;
  int iLocNumEdges;

  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  //  int numEdges;

  if (iStat >= 0) iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &dLocRecordID);
  if (iStat >= 0) osstDxf02TypHatchLoop->setRecordID(dLocRecordID);

  if (iStat >= 0) iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iLocNumEdges);
  if (iStat >= 0) osstDxf02TypHatchLoop->setNumEdges(iLocNumEdges);

  *sErrTxt = oCsvRow.GetErrorString();

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
int sstDxf02FncHatchLoopCls::Csv_Write(int iKey, sstDxf02TypHatchLoopCls *poSstHatchLoop, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0) iStat = oCsvRow.Csv_UInt4_2String( 0, poSstHatchLoop->getRecordID(), ssstDxfLib_Str);
  if (iStat >= 0) iStat = oCsvRow.Csv_Int2_2String( 0, poSstHatchLoop->getNumEdges(), ssstDxfLib_Str);


  //  int numEdges;

  return iStat;
}
//=============================================================================
int sstDxf02FncHatchLoopCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  //  int numEdges;

  oTitelStr = "RecordID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "NumEdges";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
int sstDxf02FncHatchLoopCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf02TypHatchLoopCls oSstArc;
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
int sstDxf02FncHatchLoopCls::WriteCsvFile(int iKey, std::string oDxfFilNam)
{
  sstMisc01AscFilCls oCsvFil;
  std::string oCsvFilNam;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // ===== Write all Insert to Csv file
  oCsvFilNam = oDxfFilNam + "_HatchLoop.csv";
  int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
  assert(iStat >= 0);

  std::string oCsvStr;

  this->Csv_WriteHeader(0,&oCsvStr);
  oCsvFil.Wr_StrDS1(0, &oCsvStr);

  for(dREC04RECNUMTYP kk = 1; kk <= this->count(); kk++)
  {

    sstDxf02TypHatchLoopCls oDxfHatchLoop;
    iStat = this->Read(0,kk,&oDxfHatchLoop);

    oDxfHatchLoop.setRecordID(kk);

    this->Csv_Write( 0, &oDxfHatchLoop, &oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);
  }

  iStat = oCsvFil.fcloseFil(0);
  return iStat;
}
//=============================================================================
