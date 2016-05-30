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
//  sstDxf02Base.cpp   27.02.16  Re.   27.02.16  Re.
//
//  Functions for sst dxf Base Classes
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
sstDxf02TypBaseCls::sstDxf02TypBaseCls()
{
  this->dRecordID = 0;
  this->dLayerID = 0;
  this->dLinetypeID = 0;
  this->color = 0; // int color;
  this->color24 = 0;  // int color24;
  this->width = 0;  // int width;
  this->handle = 0;  // int handle;
}
//=============================================================================
int sstDxf02TypBaseCls::getColor() const
{
  return color;
}
//=============================================================================
void sstDxf02TypBaseCls::setColor(int value)
{
  color = value;
}
//=============================================================================
void sstDxf02TypBaseCls::BaseReadFromDL(const DL_Attributes oDLAttrib)
{
  this->color = oDLAttrib.getColor();
}
//=============================================================================
void sstDxf02TypBaseCls::BaseWritToDL(DL_Attributes *poDLAttrib)
{
  poDLAttrib->setColor( this->color);
}
//=============================================================================
dREC04RECNUMTYP sstDxf02TypBaseCls::getBlockID() const
{
return dBlockID;
}
//=============================================================================
void sstDxf02TypBaseCls::setBlockID(const dREC04RECNUMTYP &value)
{
dBlockID = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf02TypBaseCls::getLayerID() const
{
return dLayerID;
}
//=============================================================================
void sstDxf02TypBaseCls::setLayerID(const dREC04RECNUMTYP &value)
{
dLayerID = value;
}
//=============================================================================
dREC04RECNUMTYP sstDxf02TypBaseCls::getRecordID() const
{
return dRecordID;
}
//=============================================================================
void sstDxf02TypBaseCls::setRecordID(const dREC04RECNUMTYP &value)
{
dRecordID = value;
}
//=============================================================================
// Constructor
sstDxf02FncBaseCls::sstDxf02FncBaseCls(dREC04RECSIZTYP iSize):sstRec04Cls(iSize)
{
  // this->oCsvRow.setDecType(1);  // set decimal point
  this->oCsvRow.SetBracket(0,(char*)"\x22");  // quotation marks
}
//=============================================================================
