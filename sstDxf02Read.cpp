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
// sstDxf02Read.cpp   27.02.16  Re.   26.02.16  Re.

#include <iostream>
#include <stdio.h>
#include <assert.h>

#include <list>

#include <dl_dxf.h>
#include <dl_creationadapter.h>

#include <rs_vector.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>

//=============================================================================
sstDxf02ReadCls::sstDxf02ReadCls(sstMisc01PrtFilCls *oTmpPrt):oDxfDb(oTmpPrt)
{
  this->poPrt = oTmpPrt;
}
//=============================================================================
sstDxf02ReadCls::~sstDxf02ReadCls()
{
  int iStat = 0;
  std::string oCsvStr;

    sstMisc01AscFilCls oCsvFil;
    std::string oCsvFilNam;

    sstDxf02FncArcCls *poArcFnc;
    poArcFnc = this->oDxfDb.getSstFncArc();

    sstDxf02FncInsertCls *poInsertFnc;
    poInsertFnc = this->oDxfDb.getSstFncInsert();

    sstDxf02FncPolylineCls *poPolylineFnc;
    poPolylineFnc = this->oDxfDb.getSstFncPolyline();

    sstDxf02FncHatchCls *poHatchFnc;
    poHatchFnc = this->oDxfDb.getSstFncHatch();

    sstDxf02FncHatchEdgeCls *poHatchEdgeFnc;
    poHatchEdgeFnc = this->oDxfDb.getSstFncHatchEdge();

    sstDxf02FncHatchLoopCls *poHatchLoopFnc;
    poHatchLoopFnc = this->oDxfDb.getSstFncHatchLoop();

    sstDxf02FncVertexCls *poVertexFnc;
    poVertexFnc = this->oDxfDb.getSstFncVertex();

    sstDxf02FncLayCls *poLayFnc;
    poLayFnc = this->oDxfDb.getSstFncLay();

    sstDxf02FncBlkCls *poBlkFnc;
    poBlkFnc = this->oDxfDb.getSstFncBlk();

    sstDxf02FncLTypeCls *poLTypeFnc;
    poLTypeFnc = this->oDxfDb.getSstFncLType();

    sstDxf02FncMainCls *poMainFnc;
    poMainFnc = this->oDxfDb.getSstFncMain();

    // write all arc data from table to csv file
    iStat = poArcFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all insert data from table to csv file
    iStat = poInsertFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all polyline data from table to csv file
    iStat = poPolylineFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all hatch data from table to csv file
    iStat = poHatchFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all hatch loop data from table to csv file
    iStat = poHatchLoopFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all hatch edge data from table to csv file
    iStat = poHatchEdgeFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all vertex data from table to csv file
    iStat = poVertexFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all layer data from table to csv file
    iStat = poLayFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all block data from table to csv file
    iStat = poBlkFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all Linetype data from table to csv file
    iStat = poLTypeFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

    // write all main data from table to csv file
    iStat = poMainFnc->WriteCsvFile(0,this->oDxfFilNam);
    assert(iStat == 0);

}
//=============================================================================
void sstDxf02ReadCls::addLayer(const DL_LayerData& data)
{
  sstDxf02TypLayCls LayDs;
  sstDxf02FncLayCls *poLayFnc;
  poLayFnc = this->oDxfDb.getSstFncLay();

  sstDxf02TypLTypeCls oLTypeRec;
  sstDxf02FncLTypeCls *poLTypeTab;
  poLTypeTab = this->oDxfDb.getSstFncLType();

  dREC04RECNUMTYP dRecNo = 0;
    int LayNamLen = 0;
    int iStat = 0;
  //-----------------------------------------------------------------------------

    // Weiteren User-Datensatz in Datenspeicher schreiben.
    LayNamLen = strlen(data.name.c_str());
    if (LayNamLen < dSSTDXFLAYERNAMELEN)
    {
      LayDs.setName(data.name.c_str());
      LayDs.setFlags( data.flags);
      LayDs.BaseReadFromDL(attributes);

      // write new Linetype record into table if not exist
      dREC04RECNUMTYP dLTypeRecNo = 0;
      oLTypeRec.setName(attributes.getLineType());
      iStat = poLTypeTab->WriteNewUnique( 0, oLTypeRec, &dLTypeRecNo);

      LayDs.setLinetypeID(dLTypeRecNo);

      // Write new record into record memory and update all trees
      iStat = poLayFnc->TreWriteNew( 0, &LayDs, &dRecNo);
      assert(iStat == 0);
    }
    else
    {
      assert(0);
    }
}
//=============================================================================
void sstDxf02ReadCls::addBlock(const DL_BlockData& data)
{
  int iStat = 0;
  sstDxf02TypBlkCls oBlk;
  dREC04RECNUMTYP dRecNo = 0;
  sstDxf02FncBlkCls *poBlkFnc;
  poBlkFnc = this->oDxfDb.getSstFncBlk();

  sstDxf02TypLTypeCls oLTypeRec;
  sstDxf02FncLTypeCls *poLTypeTab;
  poLTypeTab = this->oDxfDb.getSstFncLType();

  oBlk.setName( data.name.c_str());
  oBlk.BaseReadFromDL(attributes);

  // write new Linetype record into table if not exist
  dREC04RECNUMTYP dLTypeRecNo = 0;
  oLTypeRec.setName(attributes.getLineType());
  iStat = poLTypeTab->WriteNewUnique( 0, oLTypeRec, &dLTypeRecNo);

  oActBlockNam = data.name;

  // Write new record into record memory and update all trees
  oBlk.setLinetypeID(dLTypeRecNo);
  iStat = poBlkFnc->TreWriteNew( 0, &oBlk, &dRecNo);
  assert(iStat == 0);
}
//=============================================================================
void sstDxf02ReadCls::endBlock()
{
  oActBlockNam.clear();
}
//=============================================================================
void sstDxf02ReadCls::addPoint(const DL_PointData& data) {
    printf("POINT    (%6.3f, %6.3f, %6.3f)\n",
           data.x, data.y, data.z);
    printAttributes();
}
//=============================================================================
void sstDxf02ReadCls::addInsert(const DL_InsertData& data)
{
  int iStat = 0;
  std::string oLayerStr;
  std::string oBlockStr;

  sstDxf02FncInsertCls *poInsertFnc;
  poInsertFnc = this->oDxfDb.getSstFncInsert();
  sstDxf02FncLayCls *poLayFnc;
  poLayFnc = this->oDxfDb.getSstFncLay();
  sstDxf02FncBlkCls *poBlkFnc;
  poBlkFnc = this->oDxfDb.getSstFncBlk();
  sstDxf02FncMainCls *poMainFnc;
  poMainFnc = this->oDxfDb.getSstFncMain();

  sstDxf02TypInsertCls oDxfInsert;
  oDxfInsert.ReadFromDL(data);
  oDxfInsert.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dBlkRecNo=0;

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it element in section entities or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfInsert.setBlockID(dNumBlocks);
  }
  else
  {  // entities
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (char*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat >= 0);
    if (iStat == 0)
    {
      // layer not found in layer table
      // write new layer data record with new name, take attributes from layer 0
      oLayerStr = "0";
      sstDxf02TypLayCls oLayRec;
      iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (char*) oLayerStr.c_str(), &dLayRecNo);
      poLayFnc->Read(0,dLayRecNo,&oLayRec);
      oLayerStr = attributes.getLayer();
      oLayRec.setName(oLayerStr.c_str());
      // Write new record into record memory and update all trees
      iStat = poLayFnc->TreWriteNew( 0, &oLayRec, &dLayRecNo);

    }
    oDxfInsert.setLayerID(dLayRecNo);

    // Find block record with block name
    oBlockStr = data.name;
    iStat = poBlkFnc->TreSeaEQ( 0, poBlkFnc->getNameSortKey(), (void*) oBlockStr.c_str(), &dBlkRecNo);
    assert(iStat == 1);  // exit, if block not found in block table
    oDxfInsert.setBlockID(dBlkRecNo);
  }
  // write new insert record in insert table
  iStat = poInsertFnc->WritNew(0,&oDxfInsert,&dRecNo);
  assert(iStat == 0);

  sstDxf02TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityInsert);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);

}
//=============================================================================
void sstDxf02ReadCls::addLine(const DL_LineData& data) {
    printf("LINE     (%6.3f, %6.3f, %6.3f) (%6.3f, %6.3f, %6.3f)\n",
           data.x1, data.y1, data.z1, data.x2, data.y2, data.z2);
    printAttributes();
}
//=============================================================================
void sstDxf02ReadCls::addArc(const DL_ArcData& data) {
  int iStat = 0;
  std::string oLayerStr;

  sstDxf02TypArcCls oDxfArc;
  oDxfArc.ReadFromDL(data);
  oDxfArc.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf02FncArcCls *poArcFnc;
  poArcFnc = this->oDxfDb.getSstFncArc();
  sstDxf02FncLayCls *poLayFnc;
  poLayFnc = this->oDxfDb.getSstFncLay();
  sstDxf02FncBlkCls *poBlkFnc;
  poBlkFnc = this->oDxfDb.getSstFncBlk();
  sstDxf02FncMainCls *poMainFnc;
  poMainFnc = this->oDxfDb.getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfArc.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfArc.setLayerID(dLayRecNo);
  }
  iStat = poArcFnc->WritNew(0,&oDxfArc,&dRecNo);

  sstDxf02TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityArc);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
}
//=============================================================================
void sstDxf02ReadCls::addCircle(const DL_CircleData& data) {
    printf("CIRCLE   (%6.3f, %6.3f, %6.3f) %6.3f\n",
           data.cx, data.cy, data.cz,
           data.radius);
    printAttributes();
}
//=============================================================================
void sstDxf02ReadCls::addPolyline(const DL_PolylineData& data)
{
  int iStat = 0;

  sstDxf02TypPolylineCls oDxfPolyline;
  oDxfPolyline.ReadFromDL(data);
  oDxfPolyline.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dEntRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dLTypeRecNo=0;

  sstDxf02FncPolylineCls *poPolylineFnc;
  poPolylineFnc = this->oDxfDb.getSstFncPolyline();

  sstDxf02FncLayCls *poLayFnc;
  poLayFnc = this->oDxfDb.getSstFncLay();

  sstDxf02FncLTypeCls *poLTypeFnc;
  poLTypeFnc = this->oDxfDb.getSstFncLType();

  sstDxf02FncBlkCls *poBlkFnc;
  poBlkFnc = this->oDxfDb.getSstFncBlk();

  sstDxf02FncMainCls *poMainFnc;
  poMainFnc = this->oDxfDb.getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfPolyline.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    std::string oLayerStr;
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfPolyline.setLayerID(dLayRecNo);

    std::string oLTypeStr;
    oLTypeStr = attributes.getLineType();

    std::transform(oLTypeStr.begin(), oLTypeStr.end(),oLTypeStr.begin(), ::toupper);

    // Find record with exact search value
    iStat = poLTypeFnc->TreSeaEQ( 0, poLTypeFnc->getNameSortKey(), (void*) oLTypeStr.c_str(), &dLTypeRecNo);
    assert(iStat == 1);
    oDxfPolyline.setLinetypeID(dLTypeRecNo);

  }
  iStat = poPolylineFnc->WritNew(0,&oDxfPolyline,&dEntRecNo);

  sstDxf02TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityPolyline);
  oMainRec.setTypeID(dEntRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dMainRecNo);

  this->oDxfDb.setActRecNo(dEntRecNo);
  this->oDxfDb.setActEntType(RS2::EntityPolyline);

}
//=============================================================================
void sstDxf02ReadCls::addVertex(const DL_VertexData& data)
{
  // int iStat = 0;
  std::string oLayerStr;

  sstDxf02TypVertexCls oDxfVertex;
  oDxfVertex.ReadFromDL(data);
  // oDxfVertex.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf02FncVertexCls *poVertexFnc;
  poVertexFnc = this->oDxfDb.getSstFncVertex();
  sstDxf02FncMainCls *poMainFnc;
  poMainFnc = this->oDxfDb.getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  oDxfVertex.setParentID(this->oDxfDb.getActRecNo());
  oDxfVertex.setEntityType(this->oDxfDb.getActEntType());

  poVertexFnc->WritNew(0,&oDxfVertex,&dRecNo);

  sstDxf02TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityVertex);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  poMainFnc->WritNew(0,&oMainRec,&dRecNo);

}
//=============================================================================
void sstDxf02ReadCls::add3dFace(const DL_3dFaceData& data) {
    printf("3DFACE\n");
    for (int i=0; i<4; i++) {
        printf("   corner %d: %6.3f %6.3f %6.3f\n",
            i, data.x[i], data.y[i], data.z[i]);
    }
    printAttributes();
}
//=============================================================================
void sstDxf02ReadCls::addHatch(const DL_HatchData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf02TypHatchCls oDxfHatch;
  oDxfHatch.ReadFromDL(data);
  oDxfHatch.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dEntRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dLTypeRecNo=0;

  sstDxf02FncHatchCls *poHatchFnc;
  poHatchFnc = this->oDxfDb.getSstFncHatch();
  sstDxf02FncLayCls *poLayFnc;
  poLayFnc = this->oDxfDb.getSstFncLay();
  sstDxf02FncBlkCls *poBlkFnc;
  poBlkFnc = this->oDxfDb.getSstFncBlk();
  sstDxf02FncMainCls *poMainFnc;
  poMainFnc = this->oDxfDb.getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dNumBlocks = poBlkFnc->count();
    oDxfHatch.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = poLayFnc->TreSeaEQ( 0, poLayFnc->getNameSortKey(), (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfHatch.setLayerID(dLayRecNo);

    sstDxf02FncLTypeCls *poLTypeFnc;
    poLTypeFnc = this->oDxfDb.getSstFncLType();

    std::string oLTypeStr;
    oLTypeStr = attributes.getLineType();

    std::transform(oLTypeStr.begin(), oLTypeStr.end(),oLTypeStr.begin(), ::toupper);

    // Find record with exact search value
    iStat = poLTypeFnc->TreSeaEQ( 0, poLTypeFnc->getNameSortKey(), (void*) oLTypeStr.c_str(), &dLTypeRecNo);
    assert(iStat == 1);
    oDxfHatch.setLinetypeID(dLTypeRecNo);




  }
  iStat = poHatchFnc->WritNew(0,&oDxfHatch,&dEntRecNo);
  assert(iStat == 0);

  sstDxf02TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatch);
  oMainRec.setTypeID(dEntRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dMainRecNo);
  assert(iStat == 0);

  this->oDxfDb.setActRecNo(dEntRecNo);

}
//=============================================================================
void sstDxf02ReadCls::addHatchEdge(const DL_HatchEdgeData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf02TypHatchEdgeCls oDxfHatchEdge;
  oDxfHatchEdge.ReadFromDL(data);
  // oDxfArc.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf02FncHatchEdgeCls *poHatchEdgeFnc;
  poHatchEdgeFnc = this->oDxfDb.getSstFncHatchEdge();
  sstDxf02FncMainCls *poMainFnc;
  poMainFnc = this->oDxfDb.getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  oDxfHatchEdge.setParentID(this->oDxfDb.getActRecNo());

  iStat = poHatchEdgeFnc->WritNew(0,&oDxfHatchEdge,&dRecNo);
  assert(iStat == 0);

  sstDxf02TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatchEdge);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
  assert(iStat == 0);

}
//=============================================================================
void sstDxf02ReadCls::addHatchLoop(const DL_HatchLoopData& data)
{
  int iStat = 0;
  std::string oLayerStr;

  sstDxf02TypHatchLoopCls oDxfHatchLoop;
  oDxfHatchLoop.ReadFromDL(data);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  sstDxf02FncHatchLoopCls *poHatchLoopFnc;
  poHatchLoopFnc = this->oDxfDb.getSstFncHatchLoop();
  sstDxf02FncMainCls *poMainFnc;
  poMainFnc = this->oDxfDb.getSstFncMain();

  dREC04RECNUMTYP dNumBlocks = 0;

  iStat = poHatchLoopFnc->WritNew(0,&oDxfHatchLoop,&dRecNo);
  assert (iStat == 0);

  sstDxf02TypMainCls oMainRec;

  dREC04RECNUMTYP dMainRecNo = poMainFnc->count();

  oMainRec.setMainID(dMainRecNo+1);
  oMainRec.setEntityType(RS2::EntityHatchLoop);
  oMainRec.setTypeID(dRecNo);

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    oMainRec.setLayBlockID(dNumBlocks);
    oMainRec.setSectString("B");
  }
  else
  {  // Layer
    oMainRec.setLayBlockID(dLayRecNo);
    oMainRec.setSectString("L");
  }
  iStat = poMainFnc->WritNew(0,&oMainRec,&dRecNo);
  assert (iStat == 0);

}
//=============================================================================
//void sstDxf02ReadCls::addSolid(const DL_SolidData& data)
//{
//  // int iStat = 0;
//}
////=============================================================================
void sstDxf02ReadCls::printAttributes() {
    printf("  Attributes: Layer: %s, ", attributes.getLayer().c_str());
    printf(" Color: ");
    if (attributes.getColor()==256)	{
        printf("BYLAYER");
    } else if (attributes.getColor()==0) {
        printf("BYBLOCK");
    } else {
        printf("%d", attributes.getColor());
    }
    printf(" Width: ");
    if (attributes.getWidth()==-1) {
        printf("BYLAYER");
    } else if (attributes.getWidth()==-2) {
        printf("BYBLOCK");
    } else if (attributes.getWidth()==-3) {
        printf("DEFAULT");
    } else {
        printf("%d", attributes.getWidth());
    }
    printf(" Type: %s\n", attributes.getLineType().c_str());
}
//=============================================================================
void sstDxf02ReadCls::SetDxfFilNam(char* cTmpDxfFilNam)
{
  std::string oTmpStr;
  sstMisc01FilNamCls oFilNam;
  oTmpStr = cTmpDxfFilNam;
  // Remove extension from dxf file name and store in sst dxf read object
  oFilNam.RemoveExtension(0,"dxf",oTmpStr,&this->oDxfFilNam);
}
//=============================================================================

// EOF
