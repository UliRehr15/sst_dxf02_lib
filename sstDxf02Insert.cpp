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
//  sstDxf02Insert.cpp   27.02.16  Re.   27.02.16  Re.
//
//  Functions for sst Dxf Insert Classes
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

 
// Constructor
sstDxf02TypInsertCls::sstDxf02TypInsertCls()
{
  this->ulInsertID = 0;
  this->ulLayerID = 0;
  this->ulBlockID = 0;
  // std::string name;
  this->ipx = 0.0;
  this->ipy = 0.0;
  this->ipz = 0.0;
  this->sx = 1.0;
  this->sy = 1.0;
  this->sz = 0.0;
  this->angle = 0.0;
  this->cols = 1;
  this->rows = 1;
  this->colSp = 1.0;
  this->rowSp = 1.0;
}
 
// Set Test Data
int sstDxf02TypInsertCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  return 0;
}

void sstDxf02TypInsertCls::ReadFromDL(const DL_InsertData oDLInsert)
{
  this->ipx = oDLInsert.ipx;
  this->ipy  = oDLInsert.ipy;
  this->ipz  = oDLInsert.ipz;
  this->sx = oDLInsert.sx;
  this->sy = oDLInsert.sy;
  this->sz = oDLInsert.sz;
  this->angle = oDLInsert.angle;
  this->cols = oDLInsert.cols;
  this->rows = oDLInsert.rows;
  this->colSp = oDLInsert.colSp;
  this->rowSp = oDLInsert.rowSp;
}
//=============================================================================
void sstDxf02TypInsertCls::WritToDL(DL_InsertData *poDLInsert)
{
  poDLInsert->ipx = this->ipx;
  poDLInsert->ipy = this->ipy;
  poDLInsert->ipz = this->ipz;
  poDLInsert->sx = this->sx;
  poDLInsert->sy = this->sy;
  poDLInsert->sz = this->sz;
  poDLInsert->angle = this->angle;
  poDLInsert->cols = this->cols;
  poDLInsert->rows = this->rows;
  poDLInsert->colSp = this->colSp;
  poDLInsert->rowSp = this->rowSp;
}
//=============================================================================
unsigned long sstDxf02TypInsertCls::getLayerID() const
{
return ulLayerID;
}
//=============================================================================
void sstDxf02TypInsertCls::setLayerID(unsigned long value)
{
ulLayerID = value;
}
//=============================================================================
unsigned long sstDxf02TypInsertCls::getBlockID() const
{
return ulBlockID;
}
//=============================================================================
void sstDxf02TypInsertCls::setBlockID(unsigned long value)
{
ulBlockID = value;
}
//=============================================================================
unsigned long sstDxf02TypInsertCls::getInsertID() const
{
return ulInsertID;
}
//=============================================================================
void sstDxf02TypInsertCls::setInsertID(unsigned long value)
{
ulInsertID = value;
}
//=============================================================================
double sstDxf02TypInsertCls::getIpx() const
{
return ipx;
}
//=============================================================================
void sstDxf02TypInsertCls::setIpx(double value)
{
ipx = value;
}
//=============================================================================
double sstDxf02TypInsertCls::getIpy() const
{
return ipy;
}
//=============================================================================
void sstDxf02TypInsertCls::setIpy(double value)
{
ipy = value;
}
//=============================================================================
double sstDxf02TypInsertCls::getIpz() const
{
return ipz;
}
//=============================================================================
void sstDxf02TypInsertCls::setIpz(double value)
{
ipz = value;
}
//=============================================================================
// Constructor
sstDxf02FncInsertCls::sstDxf02FncInsertCls():sstDxf02FncBaseCls(sizeof(sstDxf02TypInsertCls))
{

}
//=============================================================================
// Csv Read Function
int sstDxf02FncInsertCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf02TypInsertCls *osstDxf02TypInsertCls)
{
  DL_InsertData sDLInsert("",
                          0,0,0,
                          1,1,0,
                          0,
                          1,1,
                          1,1);
  // DL_Attributes sDLAttribute("",0,0,"");
  unsigned long ulTmpInsertID = 0;
  unsigned long ulTmpLayerID = 0;
  unsigned long ulTmpBlockID = 0;
  int iTmpColor = 0;
  // sstStr01Cls oCsvRow;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  oCsvRow.SetReadPositon(0,0);

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpInsertID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpLayerID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpBlockID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.ipx);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.ipy);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.ipz);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &iTmpColor);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.radius);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.angle1);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.angle2);

  *sErrTxt = oCsvRow.GetErrorString();

  osstDxf02TypInsertCls->ReadFromDL(sDLInsert);

  osstDxf02TypInsertCls->setInsertID(ulTmpInsertID);
  osstDxf02TypInsertCls->setLayerID(ulTmpLayerID);
  osstDxf02TypInsertCls->setBlockID(ulTmpBlockID);
  osstDxf02TypInsertCls->setColor(iTmpColor);

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
int sstDxf02FncInsertCls::Csv_Write(int iKey, sstDxf02TypInsertCls *poSstInsert, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getInsertID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getLayerID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getBlockID(), ssstDxfLib_Str);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String( 0, poSstInsert->getIpx(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getIpy(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getIpz(), ssstDxfLib_Str);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstInsert->getColor(), ssstDxfLib_Str);


//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String( 0, poSstInsert->getCx(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getCy(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getCz(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getRadius(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getAngle1(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getAngle2(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstInsert->getColor(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf02FncInsertCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  unsigned long ulLayerID;
//  unsigned long ulBlockID;
//  double cx;
//  double cy;
//  double cz;
//  double radius;
//  double angle1;
//  double angle2;
//  int    color;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "TypeID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "LayerID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "BlockID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  oTitelStr = "ipx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

//  oTitelStr = "radius";
//  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
//  oTitelStr = "angle1";
//  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
//  oTitelStr = "angle2";
//  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  oTitelStr = "color";
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
int sstDxf02FncInsertCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf02TypInsertCls oSstInsert;
    // Read layer object from string row
    iStat = this->Csv_Read( 0, &oErrStr, &oLayStr, &oSstInsert);
    if (iStat < 0)
    {
      iStat1 = -1;
      iStat = -4;
      break;
    }
    // write layer object to recmem
    this->WritNew(0,&oSstInsert,&dRecNo);

    // Read next row from layer csv file
    oLayStr.clear();
    iStat1 = oCsvFilLayer.Rd_StrDS1 ( 2, &oLayStr);
  }

  oCsvFilLayer.fcloseFil(0);

  return iStat;
}
//=============================================================================
