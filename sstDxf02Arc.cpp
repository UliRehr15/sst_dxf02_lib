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
//  sstDxf02Arc.cpp   27.02.16  Re.   27.02.16  Re.
//
//  Functions for sst Dxf Arc Classes
//
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>
#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>

 
// Constructor
sstDxf01TypArcCls::sstDxf01TypArcCls()
{
  this->ulArcID = 0;
  this->ulLayerID = 0;
  this->ulBlockID = 0;
  this->cx = 0.0;
  this->cy = 0.0;
  this->cz = 0.0;
  this->radius = 0.0;
  this->angle1 = 0.0;
  this->angle2 = 0.0;
}
 
// Set Test Data
int sstDxf01TypArcCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;
 
  this->cx = 0.0;
  this->cy = 0.0;
  this->cz = 0.0;
  this->radius = 0.0;
  this->angle1 = 0.0;
  this->angle2 = 0.0;

  return 0;
}

void sstDxf01TypArcCls::ReadFromDL(const DL_ArcData oDLArc)
{
  this->cx = oDLArc.cx;
  this->cy = oDLArc.cy;
  this->cz = oDLArc.cz;
  this->radius = oDLArc.radius;
  this->angle1 = oDLArc.angle1;
  this->angle2 = oDLArc.angle2;
}
void sstDxf01TypArcCls::WritToDL(DL_ArcData *poDLArc)
{
  poDLArc->cx = this->cx;
  poDLArc->cy = this->cy;
  poDLArc->cz = this->cz;
  poDLArc->radius = this->radius;
  poDLArc->angle1 = this->angle1;
  poDLArc->angle2 = this->angle2;
}
double sstDxf01TypArcCls::getCx() const
{
  return this->cx;
}
void sstDxf01TypArcCls::setCx(double value)
{
  this->cx = value;
}
double sstDxf01TypArcCls::getCy() const
{
  return this->cy;
}
void sstDxf01TypArcCls::setCy(double value)
{
  this->cy = value;
}
double sstDxf01TypArcCls::getCz() const
{
  return this->cz;
}
void sstDxf01TypArcCls::setCz(double value)
{
  this->cz = value;
}
double sstDxf01TypArcCls::getRadius() const
{
  return this->radius;
}
void sstDxf01TypArcCls::setRadius(double value)
{
  this->radius = value;
}
double sstDxf01TypArcCls::getAngle1() const
{
  return this->angle1;
}
void sstDxf01TypArcCls::setAngle1(double value)
{
  this->angle1 = value;
}
double sstDxf01TypArcCls::getAngle2() const
{
  return this->angle2;
}
void sstDxf01TypArcCls::setAngle2(double value)
{
  this->angle2 = value;
}

unsigned long sstDxf01TypArcCls::getLayerID() const
{
return ulLayerID;
}

void sstDxf01TypArcCls::setLayerID(unsigned long value)
{
ulLayerID = value;
}

unsigned long sstDxf01TypArcCls::getBlockID() const
{
return ulBlockID;
}

void sstDxf01TypArcCls::setBlockID(unsigned long value)
{
ulBlockID = value;
}
unsigned long sstDxf01TypArcCls::getArcID() const
{
return ulArcID;
}

void sstDxf01TypArcCls::setArcID(unsigned long value)
{
ulArcID = value;
}
//=============================================================================
// Constructor
sstDxf01FncArcCls::sstDxf01FncArcCls():sstDxf01FncBaseCls(sizeof(sstDxf01TypArcCls))
{
  // this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf01TypArcCls));
}
//=============================================================================
// Csv Read Function
int sstDxf01FncArcCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf01TypArcCls *osstDxf01TypArcCls)
{
  DL_ArcData sDLArc(0.0,0.0,0.0,0.0,0.0,0.0);
  unsigned long ulTmpArcID = 0;
  unsigned long ulTmpLayerID = 0;
  unsigned long ulTmpBlockID = 0;
  sstStr01Cls oCsvRow;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpArcID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpLayerID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpBlockID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLArc.cx);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLArc.cy);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLArc.cz);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLArc.radius);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLArc.angle1);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLArc.angle2);

  *sErrTxt = oCsvRow.GetErrorString();

  osstDxf01TypArcCls->ReadFromDL(sDLArc);

  osstDxf01TypArcCls->setArcID(ulTmpArcID);
  osstDxf01TypArcCls->setLayerID(ulTmpLayerID);
  osstDxf01TypArcCls->setBlockID(ulTmpBlockID);

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
int sstDxf01FncArcCls::Csv_Write(int iKey, sstDxf01TypArcCls *poSstARC, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstARC->getArcID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstARC->getLayerID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstARC->getBlockID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String( 0, poSstARC->getCx(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstARC->getCy(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstARC->getCz(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstARC->getRadius(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstARC->getAngle1(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstARC->getAngle2(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstARC->getColor(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf01FncArcCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
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

  oTitelStr = "ArcID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "LayerID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "BlockID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "cx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "cy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "cz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "radius";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "angle1";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "angle2";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
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
int sstDxf01FncArcCls::ReadCsvFile(int iKey, std::string oFilNam)
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
    sstDxf01TypArcCls oSstArc;
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
