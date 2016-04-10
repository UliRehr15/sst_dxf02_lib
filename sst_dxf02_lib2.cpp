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
// sst_dxf02_lib2.cpp    01.08.12  Re.    01.08.12  Re.
//
// Several functions for dxf output
//


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

// #include <kern.h>
// #include <mathem.h>
// #include <str_lib.h>
// #include <sstlib.h>
// #include <dl_dxf.h>
// #include <sst_dxf_lib.h>

//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_FileOpen (int         iKey,
                     DL_Dxf     **dxf,
                     DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  *dxf = new DL_Dxf();
  DL_Codes::version exportVersion = DL_Codes::AC1015;
  *dw = (*dxf)->out("myfile.dxf", exportVersion);
  if (*dw==NULL) {
      printf("Cannot open file 'myfile.dxf' \
             for writing.");
      // abort function e.g. with return
             iRet = -1;
  }

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_FileClose (int          iKey,
                      DL_Dxf     **dxf,
                      DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Write buffer to dxf file and close
  (*dxf)->writeObjects(**dw);
  (*dxf)->writeObjectsEnd(**dw);
  (*dw)->dxfEOF();
  (*dw)->close();
  delete *dw;
  delete *dxf;

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_WrtSecHeader (int         iKey,
                         DL_Dxf     **dxf,
                         DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Write Header-------------------------------------------------------------

  (*dxf)->writeHeader(**dw);
  // int variable:
  (*dw)->dxfString(9, "$INSUNITS");
  (*dw)->dxfInt(70, 4);
  // real (double, float) variable:
  (*dw)->dxfString(9, "$DIMEXE");
  (*dw)->dxfReal(40, 1.25);
  // string variable:
  (*dw)->dxfString(9, "$TEXTSTYLE");
  (*dw)->dxfString(7, "Standard");
  // vector variable:
  (*dw)->dxfString(9, "$LIMMIN");
  (*dw)->dxfReal(10, 0.0);
  (*dw)->dxfReal(20, 0.0);
  (*dw)->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_WrtSecLayers (int         iKey,
                         DL_Dxf     **dxf,
                         DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Section Tables -------------------------------------------------------------

  int numberOfLayers = 3;
  (*dw)->tableLayers(numberOfLayers);

  (*dxf)->writeLayer(**dw,
                 DL_LayerData("0", 0),
                 DL_Attributes(
                     std::string(""),      // leave empty
                     DL_Codes::black,        // default color
                     100,                  // default width
                     "CONTINUOUS"));       // default line style

  (*dxf)->writeLayer(**dw,
                 DL_LayerData("mainlayer", 0),
                 DL_Attributes(
                     std::string(""),
                     DL_Codes::red,
                     100,
                     "CONTINUOUS"));

  (*dxf)->writeLayer(**dw,
                 DL_LayerData("anotherlayer", 0),
                 DL_Attributes(
                     std::string(""),
                     DL_Codes::black,
                     100,
                     "CONTINUOUS"));

  (*dw)->tableEnd();


  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_WrtSecBlocks (int         iKey,
                         DL_Dxf     **dxf,
                         DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Section Blocks

  (*dw)->sectionBlocks();

  (*dxf)->writeBlock(**dw,
                 DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
  (*dxf)->writeEndBlock(**dw, "*Model_Space");

  (*dxf)->writeBlock(**dw,
                 DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
  (*dxf)->writeEndBlock(**dw, "*Paper_Space");

  (*dxf)->writeBlock(**dw,
                 DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
  (*dxf)->writeEndBlock(**dw, "*Paper_Space0");

  (*dxf)->writeBlock(**dw,
                 DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));
  // ...
  // write block entities e.g. with dxf->writeLine(), ..
  // ...
  (*dxf)->writeEndBlock(**dw, "myblock1");

  (*dxf)->writeBlock(**dw,
                 DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));
  // ...
  // write block entities e.g. with dxf->writeLine(), ..
  // ...
  (*dxf)->writeEndBlock(**dw, "myblock2");

  (*dw)->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_WrtSecTypes (int          iKey,
                        DL_Dxf     **dxf,
                        DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Section Types -------------------------------------------------------------

  (*dw)->sectionTables();
  (*dxf)->writeVPort(**dw);
  (*dw)->tableLineTypes(25);
  (*dxf)->writeLineType(**dw, DL_LineTypeData("BYBLOCK", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("BYLAYER", 0));
  (*dxf)->writeLineType(**dw,
                    DL_LineTypeData("CONTINUOUS", 0));
  (*dxf)->writeLineType(**dw,
                    DL_LineTypeData("ACAD_ISO02W100", 0));
  (*dxf)->writeLineType(**dw,
                    DL_LineTypeData("ACAD_ISO03W100", 0));
  (*dxf)->writeLineType(**dw,
                    DL_LineTypeData("ACAD_ISO04W100", 0));
  (*dxf)->writeLineType(**dw,
                    DL_LineTypeData("ACAD_ISO05W100", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("BORDER", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("BORDER2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("BORDERX2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("CENTER", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("CENTER2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("CENTERX2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DASHDOT", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DASHDOT2", 0));
  (*dxf)->writeLineType(**dw,
                    DL_LineTypeData("DASHDOTX2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DASHED", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DASHED2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DASHEDX2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DIVIDE", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DIVIDE2", 0));
  (*dxf)->writeLineType(**dw,
                    DL_LineTypeData("DIVIDEX2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DOT", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DOT2", 0));
  (*dxf)->writeLineType(**dw, DL_LineTypeData("DOTX2", 0));
  (*dw)->tableEnd();


  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_WrtSecStyles (int          iKey,
                         DL_Dxf     **dxf,
                         DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;


  //--- Section Styles

  (*dxf)->writeStyle(**dw,DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "standard", ""));
  (*dxf)->writeView(**dw);
  (*dxf)->writeUcs(**dw);

  (*dw)->tableAppid(1);
  (*dw)->tableAppidEntry(0x12);
  (*dw)->dxfString(2, "ACAD");
  (*dw)->dxfInt(70, 0);
  (*dw)->tableEnd();
  (*dxf)->writeDimStyle(**dw,
                    1,
                    1,
                    1,
                    1,
                    1);
  (*dxf)->writeBlockRecord(**dw);
  (*dxf)->writeBlockRecord(**dw, "myblock1");
  (*dxf)->writeBlockRecord(**dw, "myblock2");
  (*dw)->tableEnd();
  (*dw)->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_WrtSecEntities (int          iKey,
                           DL_Dxf     **dxf,
                           DL_WriterA **dw)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //-- Sections Entities

  (*dw)->sectionEntities();

  // write all your entities..
  (*dxf)->writePoint(
      **dw,
      DL_PointData(10.0,
                   45.0,
                   0.0),
      DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

  (*dxf)->writeLine(
      **dw,
      DL_LineData(25.0,   // start point
                  30.0,
                  0.0,
                  100.0,   // end point
                  120.0,
                  0.0),
      DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

  (*dw)->sectionEnd();

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstdxf_WrtDss2PolyLine (int           iKey,
                            sstRec04Cls  *sPntDss,
                            DL_Dxf      **dxf,
                            DL_WriterA  **dw)
//-----------------------------------------------------------------------------
{
  // D3Pkt_stru     sD3Pnt;
  RS_Vector     sD3Pnt;
  dREC04RECNUMTYP   lAnzDs=0;
  dREC04RECNUMTYP   ii=0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Die Anzahl der aktuell gespeicherten Datensätze zurückgeben.
  // iStat = DS1_DsAnz ( 0, sPntDss, &lAnzDs);
  lAnzDs = sPntDss->count();

  (*dxf)->writePolyline(**dw, DL_PolylineData (lAnzDs,0,0,0),
                         DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

  for (ii=1; ii<=lAnzDs; ii++)
  {
    // tat = sPntDss->Read(0,ii,&sD3Pnt);

    (*dxf)->writeVertex( **dw, DL_VertexData(sD3Pnt.x, sD3Pnt.y, 0.0));
  }

  (*dxf)->writePolylineEnd(**dw);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
