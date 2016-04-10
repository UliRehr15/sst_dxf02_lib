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

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>

//=============================================================================
// Constructor
sstDxf01TypBaseCls::sstDxf01TypBaseCls()
{
  this->color = 0; // int color;
  this->color24 = 0;  // int color24;
  this->width = 0;  // int width;
  // std::string lineType;
  this->handle = 0;  // int handle;
}
//=============================================================================
int sstDxf01TypBaseCls::getColor() const
{
  return color;
}
//=============================================================================
void sstDxf01TypBaseCls::setColor(int value)
{
  color = value;
}
//=============================================================================
void sstDxf01TypBaseCls::BaseReadFromDL(const DL_Attributes oDLAttrib)
{
  this->color = oDLAttrib.getColor();
}
//=============================================================================
void sstDxf01TypBaseCls::BaseWritToDL(DL_Attributes *poDLAttrib)
{
  poDLAttrib->setColor( this->color);
}
//=============================================================================
// Constructor
sstDxf01FncBaseCls::sstDxf01FncBaseCls(dREC04RECSIZTYP iSize):sstRec04Cls(iSize)
{
  // this->oCsvRow.setDecType(1);  // set decimal point
  this->oCsvRow.SetBracket(0,(char*)"\x22");  // quotation marks
}
//=============================================================================
