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
//  sstDxf02Text.cpp   06.07.16  Re.   06.07.16  Re.
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
sstDxf02TypTextCls::sstDxf02TypTextCls()
{
 
}
 
// // Constructor
sstDxf02FncTextCls::sstDxf02FncTextCls():sstDxf02FncBaseCls(sizeof(sstDxf02TypTextCls))
{
 
}
 
// // Csv Read Function
int sstDxf02FncTextCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf02TypTextCls *osstDxf02TypText)
{
  int iStat = 0;
//  Bloc Function1 Start
//  StrDS1_stru sErrTxt;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
 
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->ipx);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->ipy);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->ipz);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->apx);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->apy);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->apz);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->height);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->xScaleFactor);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypText->textGenerationFlags);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypText->hJustification);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxf02_Str, &osstDxf02TypText->vJustification);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Char( 0, ssstDxf02_Str, osstDxf02TypText->text,101);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxf02_Str, &osstDxf02TypText->style_ID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxf02_Str, &osstDxf02TypText->angle);
 
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
int sstDxf02FncTextCls::Csv_Write(int iKey, sstDxf02TypTextCls *osstDxf02TypText, std::string *ssstDxf02_Str)
{
  int iStat = 0;
//  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;
 
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->ipx, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->ipy, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->ipz, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->apx, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->apy, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->apz, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->height, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->xScaleFactor, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypText->textGenerationFlags, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypText->hJustification, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, osstDxf02TypText->vJustification, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String ( 0, osstDxf02TypText->text, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String ( 0, osstDxf02TypText->style_ID, ssstDxf02_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, osstDxf02TypText->angle, ssstDxf02_Str);
 
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
