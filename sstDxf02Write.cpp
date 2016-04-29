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
// sstDxf01Write.cpp    05.04.16  Re.    05.04.16  Re.
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

// #include "sstCsv2Dxf.h"

//=============================================================================
//sstDxf02WriteCls::sstDxf02WriteCls()
//{

//}
////=============================================================================
//sstDxf02WriteCls::~sstDxf02WriteCls()
//{

//}
//=============================================================================
sstDxf02WriteCls::sstDxf02WriteCls (sstMisc01PrtFilCls *oTmpPrt):oDxfDb(oTmpPrt)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  // if ( iKey != 0) return -1;

  // *dxf = new DL_Dxf();
  this->dxf = new DL_Dxf();

  this->poPrt = oTmpPrt;


//  DL_Codes::version exportVersion = DL_Codes::AC1015;
//  // *dw = (*dxf)->out("myfile.dxf", exportVersion);
//  this->dw = this->dxf->out("myfile2.dxf", exportVersion);
//  if (this->dw == NULL) {
//      printf("Cannot open file 'myfile.dxf'
//             for writing.");
//      // abort function e.g. with return
//             iRet = -1;
//  }

  // this->oDxfDB = oTmpDxfDB;

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  // return iRet;
}
//=============================================================================
sstDxf02WriteCls::~sstDxf02WriteCls ()
//-----------------------------------------------------------------------------
{
  //--- Write buffer to dxf file and close
//  this->dxf->writeObjects(*this->dw);
//  this->dxf->writeObjectsEnd(*this->dw);
  this->dw->dxfEOF();
  this->dw->close();
  delete this->dw;
  delete this->dxf;

}
//=============================================================================
int sstDxf02WriteCls::OpenNewDxfFile (int  iKey, std::string oDxfFilNam)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  DL_Codes::version exportVersion = DL_Codes::AC1015;
  this->dw = this->dxf->out(oDxfFilNam.c_str(), exportVersion);
  if (this->dw == NULL) {
      printf("Cannot open file 'myfile.dxf' \
             for writing.");
      // abort function e.g. with return
             iStat = -1;
  }
  return iStat;
}
//=============================================================================
int sstDxf02WriteCls::WrtSecHeader (int         iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Write Header-------------------------------------------------------------

  this->dxf->writeHeader(*this->dw);
  // int variable:
  this->dw->dxfString(9, "$INSUNITS");
  this->dw->dxfInt(70, 4);
  // real (double, float) variable:
  this->dw->dxfString(9, "$DIMEXE");
  this->dw->dxfReal(40, 1.25);
  // string variable:
  this->dw->dxfString(9, "$TEXTSTYLE");
  this->dw->dxfString(7, "Standard");
  // vector variable:
  this->dw->dxfString(9, "$LIMMIN");
  this->dw->dxfReal(10, 0.0);
  this->dw->dxfReal(20, 0.0);
  this->dw->sectionEnd();

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
int sstDxf02WriteCls::WrtSecLayers (int         iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Section Tables -------------------------------------------------------------


//  this->dxf->writeLayer(*this->dw,
//                 DL_LayerData("0", 0),
//                 DL_Attributes(
//                     std::string(""),      // leave empty
//                     DL_Codes::black,        // default color
//                     100,                  // default width
//                     "CONTINUOUS"));       // default line style

//  this->dxf->writeLayer(*this->dw,
//                 DL_LayerData("mainlayer", 0),
//                 DL_Attributes(
//                     std::string(""),
//                     DL_Codes::red,
//                     100,
//                     "CONTINUOUS"));

//  this->dxf->writeLayer(*this->dw,
//                 DL_LayerData("anotherlayer", 0),
//                 DL_Attributes(
//                     std::string(""),
//                     DL_Codes::black,
//                     100,
//                     "CONTINUOUS"));

  sstDxf02FncLayCls *oLocSstFncLay = NULL;        /**< layer recmem object */
  oLocSstFncLay = this->oDxfDb.getSstFncLay();
  dREC04RECNUMTYP dNumLayers = oLocSstFncLay->count();

  // int numberOfLayers = 3;
  this->dw->tableLayers((int) dNumLayers);

  sstDxf02TypLayCls oLayRec;

  for (dREC04RECNUMTYP dd=1; dd <= dNumLayers; dd++)
  {
    iStat = oLocSstFncLay->Read(0,dd,&oLayRec);

    this->dxf->writeLayer(*this->dw,
                   DL_LayerData(oLayRec.getName(), 0),
                   DL_Attributes(
                       std::string(""),
                       DL_Codes::black,
                       100,
                       "CONTINUOUS"));
  }

  this->dw->tableEnd();


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
int sstDxf02WriteCls::WrtSecBlocks (int         iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstDxf02FncMainCls *oLocSstFncMain = NULL;              /**< main recmem object */
  sstDxf02TypMainCls oMainRec;
  oLocSstFncMain = this->oDxfDb.getSstFncMain();

//  sstDxf02FncLayCls *oLocSstFncLay = NULL;              /**< layer recmem object */
//  sstDxf02TypLayCls oLayRec;
//  oLocSstFncLay = this->oDxfDb.getSstFncLay();

  sstDxf02FncBlkCls *oLocSstFncBlk = NULL;              /**< Block recmem object */
  sstDxf02TypLayCls oBlkRec;
  oLocSstFncBlk = this->oDxfDb.getSstFncBlk();

  sstDxf02FncArcCls *oLocSstFncArc = NULL;              /**< Arc recmem object */
  sstDxf02TypArcCls oArcRec;
  oLocSstFncArc = this->oDxfDb.getSstFncArc();

//  sstDxf02FncInsertCls *oLocSstFncInsert = NULL;        /**< insert recmem object */
//  sstDxf02TypInsertCls oInsertRec;
//  oLocSstFncInsert = this->oDxfDb.getSstFncInsert();

  // dREC04RECNUMTYP dNumInserts = oLocSstFncInsert->count();


  // Section Blocks

  this->dw->sectionBlocks();

  this->dxf->writeBlock(*this->dw,
                 DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
  this->dxf->writeEndBlock(*this->dw, "*Model_Space");

  this->dxf->writeBlock(*this->dw,
                 DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
  this->dxf->writeEndBlock(*this->dw, "*Paper_Space");

  this->dxf->writeBlock(*this->dw,
                 DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
  this->dxf->writeEndBlock(*this->dw, "*Paper_Space0");

  // Write one Symobl definition ================================================

  dxf->writeBlock(*dw,
                 DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));
  // ...
  // write block entities e.g. with dxf->writeLine(), ..

  dxf->writeLine(
      *dw,
      DL_LineData(0.0,   // start point
                  0.0,
                  0.0,
                  1.0,   // end point
                  1.0,
                  0.0),
      DL_Attributes("myblock1", 256, -1, "BYBLOCK"));

  dxf->writeLine(
      *dw,
      DL_LineData(0.0,   // start point
                  1.0,
                  0.0,
                  1.0,   // end point
                  0.0,
                  0.0),
      DL_Attributes("myblock1", 256, -1, "BYBLOCK"));

  // ...
  dxf->writeEndBlock(*dw, "myblock1");
  // End Symobl definition ================================================

  dxf->writeBlock(*dw,
                 DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));
  // ...
  // write block entities e.g. with dxf->writeLine(), ..
  // ...
  dxf->writeEndBlock(*dw, "myblock2");

  dREC04RECNUMTYP dActBlockID = 0;
  dREC04RECNUMTYP dNumMains = oLocSstFncMain->count();
  for (dREC04RECNUMTYP ii=1;ii <= dNumMains;ii++)
  {
    iStat = oLocSstFncMain->Read( 0, ii, &oMainRec);
    std::string oSectStr = oMainRec.getSectString();
    iStat = oSectStr.compare("B");
    if(iStat == 0)
    {  // we are inside Block section

      if (oMainRec.getLayBlockID() != dActBlockID)
      {  // new block!!
        // if current block is not empty, write to dxf file
        if (oBlkRec.getLayerID() != 0)
        {
          dxf->writeEndBlock(*dw, oBlkRec.getName());
        }
        dActBlockID = oMainRec.getLayBlockID();
        iStat = oLocSstFncBlk->Read( 0, oMainRec.getLayBlockID(), &oBlkRec);
        dxf->writeBlock(*dw,
                       DL_BlockData(oBlkRec.getName(), 0, 0.0, 0.0, 0.0));

      }
      switch (oMainRec.getEntityType())
      {
        case RS2::EntityArc:
        {
          iStat = oLocSstFncArc->Read(0,oMainRec.getTypeID(),&oArcRec);
          DL_ArcData oDL_Arc( 0.0,0.0,0.0,
                              1.0,        // Radius
                              0.0,0.0);   // Angle1, angle2
          oArcRec.WritToDL(&oDL_Arc);

          // set Blockname
          // oDL_Insert.name = "myblock1";

          // write next insert into dxf file
          this->dxf->writeArc(  *this->dw,
                                oDL_Arc,
                                DL_Attributes(oBlkRec.getName(), 256, -1, "BYBLOCK"));

        }
        break;
      default:
        break;
      }

    }
    else break;

  }

  dxf->writeEndBlock(*dw, oBlkRec.getName());

  this->dw->sectionEnd();

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
int sstDxf02WriteCls::WrtSecTypes (int          iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //--- Section Types -------------------------------------------------------------



  this->dw->sectionTables();
  this->dxf->writeVPort(*this->dw);
  this->dw->tableLineTypes(25);
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("BYBLOCK", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("BYLAYER", 0));
  this->dxf->writeLineType(*this->dw,
                    DL_LineTypeData("CONTINUOUS", 0));
  this->dxf->writeLineType(*this->dw,
                    DL_LineTypeData("ACAD_ISO02W100", 0));
  this->dxf->writeLineType(*this->dw,
                    DL_LineTypeData("ACAD_ISO03W100", 0));
  this->dxf->writeLineType(*this->dw,
                    DL_LineTypeData("ACAD_ISO04W100", 0));
  this->dxf->writeLineType(*this->dw,
                    DL_LineTypeData("ACAD_ISO05W100", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("BORDER", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("BORDER2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("BORDERX2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("CENTER", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("CENTER2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("CENTERX2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DASHDOT", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DASHDOT2", 0));
  this->dxf->writeLineType(*this->dw,
                    DL_LineTypeData("DASHDOTX2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DASHED", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DASHED2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DASHEDX2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DIVIDE", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DIVIDE2", 0));
  this->dxf->writeLineType(*this->dw,
                    DL_LineTypeData("DIVIDEX2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DOT", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DOT2", 0));
  this->dxf->writeLineType(*this->dw, DL_LineTypeData("DOTX2", 0));
  this->dw->tableEnd();

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
int sstDxf02WriteCls::WrtSecStyles (int          iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;


  //--- Section Styles

  this->dxf->writeStyle(*this->dw,DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "standard", ""));
  this->dxf->writeView(*this->dw);
  this->dxf->writeUcs(*this->dw);

  this->dw->tableAppid(1);
  this->dw->tableAppidEntry(0x12);
  this->dw->dxfString(2, "ACAD");
  this->dw->dxfInt(70, 0);
  this->dw->tableEnd();
  this->dxf->writeDimStyle(*this->dw,
                    1,
                    1,
                    1,
                    1,
                    1);
  this->dxf->writeBlockRecord(*this->dw);
  this->dxf->writeBlockRecord(*this->dw, "myblock1");
  this->dxf->writeBlockRecord(*this->dw, "myblock2");
  this->dw->tableEnd();
  this->dw->sectionEnd();

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
int sstDxf02WriteCls::WrtSecEntities (int          iKey)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  //-- Sections Entities

  this->dw->sectionEntities();

  sstDxf02FncLayCls *oLocSstFncLay = NULL;              /**< layer recmem object */
  sstDxf02TypLayCls oLayRec;
  oLocSstFncLay = this->oDxfDb.getSstFncLay();

  sstDxf02FncBlkCls *oLocSstFncBlk = NULL;              /**< Block recmem object */
  sstDxf02TypBlkCls oBlkRec;
  oLocSstFncBlk = this->oDxfDb.getSstFncBlk();

  sstDxf02FncInsertCls *oLocSstFncInsert = NULL;        /**< insert recmem object */
  oLocSstFncInsert = this->oDxfDb.getSstFncInsert();
  dREC04RECNUMTYP dNumInserts = oLocSstFncInsert->count();

  // int numberOfLayers = 3;
  // this->dw->tableLayers((int) dNumLayers);

  sstDxf02TypInsertCls oInsertRec;
  DL_InsertData oDL_Insert("",
                           0.0,0.0,0.0,
                           1.0,1.0,0.0,
                           0.0,
                           1,1,
                           1.0,1.0);

  for (dREC04RECNUMTYP dd=1; dd <= dNumInserts; dd++)
  {
    iStat = oLocSstFncInsert->Read(0,dd,&oInsertRec);
    assert(iStat == 0);
    iStat = oLocSstFncLay->Read(0,oInsertRec.getLayerID(),&oLayRec);
    assert(iStat == 0);
    iStat = oLocSstFncBlk->Read(0,oInsertRec.getBlockID(),&oBlkRec);
    assert(iStat == 0);

    // write Insert record data to dxflib insert
    oInsertRec.WritToDL(&oDL_Insert);

    // set Blockname
    // oDL_Insert.name = "myblock1";
    oDL_Insert.name = oBlkRec.getName();

    // write next insert into dxf file
    this->dxf->writeInsert(  *this->dw,
                              oDL_Insert,
                              DL_Attributes(oLayRec.getName(), 256, -1, "BYLAYER"));
  }

  sstDxf02FncArcCls *oLocSstFncArc = NULL;        /**< insert recmem object */
  oLocSstFncArc = this->oDxfDb.getSstFncArc();
  dREC04RECNUMTYP dNumArcs = oLocSstFncArc->count();

  // int numberOfLayers = 3;
  // this->dw->tableLayers((int) dNumLayers);

  sstDxf02TypArcCls oArcRec;
  DL_ArcData oDL_Arc( 0.0,0.0,0.0,
                      1.0,        // Radius
                      0.0,0.0);   // Angle1, angle2

  for (dREC04RECNUMTYP dd=1; dd <= dNumArcs; dd++)
  {
    iStat = oLocSstFncArc->Read(0,dd,&oArcRec);
    assert(iStat == 0);

    // If Arc is entity element
    if(oArcRec.getLayerID() > 0)
    {
      iStat = oLocSstFncLay->Read(0,oArcRec.getLayerID(),&oLayRec);
      assert(iStat == 0);
      oArcRec.WritToDL(&oDL_Arc);

      // set Blockname
      // oDL_Insert.name = "myblock1";

      // write next insert into dxf file
      this->dxf->writeArc(  *this->dw,
                            oDL_Arc,
                            DL_Attributes(oLayRec.getName(), 256, -1, "BYLAYER"));

    }
  }

  //  // write all your entities..
  //  this->dxf->writePoint(
  //      *this->dw,
  //      DL_PointData(10.0,
  //                   45.0,
  //                   0.0),
  //      DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

//  this->dxf->writeLine(
//      *this->dw,
//      DL_LineData(25.0,   // start point
//                  30.0,
//                  0.0,
//                  100.0,   // end point
//                  120.0,
//                  0.0),
//      DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

  this->dw->sectionEnd();

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
int sstDxf02WriteCls::WrtSecObjects (int          iKey)
//-----------------------------------------------------------------------------
{
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  this->dxf->writeObjects(*this->dw);
  this->dxf->writeObjectsEnd(*this->dw);

  return 0;
}
//=============================================================================
int sstDxf02WriteCls::WrtDss2PolyLine (int           iKey,
                            sstRec04Cls  *sPntDss)
//-----------------------------------------------------------------------------
{
  RS_Vector     sD3Pnt;
  dREC04RECNUMTYP   lAnzDs=0;
  dREC04RECNUMTYP   ii=0;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Die Anzahl der aktuell gespeicherten Datens�tze zur�ckgeben.
  // iStat = DS1_DsAnz ( 0, sPntDss, &lAnzDs);
  lAnzDs = sPntDss->count();

  this->dxf->writePolyline(*this->dw, DL_PolylineData (lAnzDs,0,0,0),
                         DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

  for (ii=1; ii<=lAnzDs; ii++)
  {
    // tat = sPntDss->Read(0,ii,&sD3Pnt);

    this->dxf->writeVertex( *this->dw, DL_VertexData(sD3Pnt.x, sD3Pnt.y, 0.0));
  }

  this->dxf->writePolylineEnd(*this->dw);

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
void sstDxf02WriteCls::SetDxfFilNam(std::string oTmpDxfFilNam)
{
  // std::string oTmpStr;
  sstMisc01FilNamCls oFilNam;
  // oTmpStr = cTmpDxfFilNam;
  // Remove extension from dxf file name and store in sst dxf read object
  oFilNam.RemoveExtension(0,"dxf", oTmpDxfFilNam,&this->oDxfFilNam);
}
//=============================================================================
int sstDxf02WriteCls::ReadAllCsvFiles(int iKey)
{
  if ( iKey != 0) return -1;

  return this->oDxfDb.ReadAllCsvFiles(0,this->oDxfFilNam);
}
//=============================================================================