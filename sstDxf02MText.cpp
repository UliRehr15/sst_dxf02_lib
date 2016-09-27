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
//  sstDxf02MText.cpp   06.07.16  Re.   06.07.16  Re.
//
//  Functions for Class "sstDxf02Lib"
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
 
#include "sstDxf02Lib.h"
 
// Constructor
sstDxf02TypMTextCls::sstDxf02TypMTextCls()
{
 
}
 
// // Constructor
sstDxf02FncMTextCls::sstDxf02FncMTextCls():sstDxf02FncBaseCls(sizeof(sstDxf02TypMTextCls))
{
 
}
 
// // Csv Read Function
int sstDxf02FncMTextCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf02TypMTextCls *osstDxf02TypMText)
{
  int iStat = 0;
//  Bloc Function1 Start
//  StrDS1_stru sErrTxt;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->ipx);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->ipy);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->ipz);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->dirx);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->diry);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->dirz);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->height);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->width);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypMText->attachmentPoint);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypMText->drawingDirection);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypMText->lineSpacingStyle);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->lineSpacingFactor);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Char( 0, ssstDxf02_Str, osstDxf02TypMText->text,101);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxf02_Str, &osstDxf02TypMText->style_ID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypMText->angle);
 
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
 
// // Csv Write Function
int sstDxf02FncMTextCls::Csv_Write(int iKey, sstDxf02TypMTextCls *osstDxf02TypMText, std::string *ssstDxf02_Str)
{
  int iStat = 0;
//  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;
 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->ipx, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->ipy, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->ipz, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->dirx, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->diry, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->dirz, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->height, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->width, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypMText->attachmentPoint, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypMText->drawingDirection, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypMText->lineSpacingStyle, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->lineSpacingFactor, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String ( 0, osstDxf02TypMText->text, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String ( 0, osstDxf02TypMText->style_ID, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypMText->angle, ssstDxf02_Str);
 
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
