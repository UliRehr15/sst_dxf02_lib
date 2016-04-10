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
// sst_dxf02_lib1.cpp    22.04.10 Re.    16.04.10  Re.
//
// functions
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <iostream>
#include <list>

#include <dl_dxf.h>
#include <dl_attributes.h>
#include <dl_creationadapter.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>


// #include "sst_dxf_lib.h"

sstDxfBase_Cls::sstDxfBase_Cls()
{
  // int iStat = 0;
  ulID = 0;
  memset(cName,0,33);
  // Initialize Min-Max
  // Mia_2Ini_c ( 0, &sMiMa);
}
//=============================================================================
void sstDxfBase_Cls::SetId(unsigned long ulLocID)
{
  ulID = ulLocID;
}
//=============================================================================
void sstDxfBase_Cls::GetId(unsigned long *uiLocID)
{
  *uiLocID = ulID;
}
//=============================================================================
void sstDxfBase_Cls::SetName( char *cLocName)
{
  strncpy(cName,cLocName,32);
}
//=============================================================================
void sstDxfBase_Cls::GetName( char *cLocName, unsigned int uiLocNamLen)
{
  strncpy(cLocName, cName, uiLocNamLen-1);
  cLocName[uiLocNamLen-1] = 0;
}
//=============================================================================
//int sstDxfBase_Cls::GetMinMax (int             iKey,
//                               MIMA_2D_Struct *sLocMiMa)
//{
//  // int iStat = 0;

//  if ( iKey != 0) return -1;

//  *sLocMiMa = sMiMa;

//  return 0;
//}
//=============================================================================
//int sstDxfBase_Cls::UpdateMinMax (int             iKey,
//                                  DL_VertexData oVertex)
//{
//  int iStat = 0;

//  if ( iKey != 0) return -1;

//  // update MinMax with new vertex
//  iStat = Mia_2Koor_c ( 0, &sMiMa, oVertex.x, oVertex.y);

//  return iStat;
//}
//=============================================================================
//int sstDxfBase_Cls::ResetMinMax (int    iKey)
//{
//  int iStat = 0;

//  if ( iKey != 0) return -1;

//  // Initialize Min-Max
//  iStat = Mia_2Ini_c ( 0, &sMiMa);

//  return iStat;
//}
//=============================================================================
int sstDxfPolylineCls::AddVertex(int            iKey,
                                 DL_VertexData *oVertex)
{
  DL_VertexData sTestData;
  // DL_VertexData *pTestData;
  // long lNewHeapMax = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

//  if (sVertexHeap.AnzDs >= sVertexHeap.MaxDs)
//  {
//    lNewHeapMax = sVertexHeap.MaxDs * 2;
//    if (lNewHeapMax == 0) lNewHeapMax=1;
//    iStat = SST_HPO_Rea_c( 0, &sVertexHeap, lNewHeapMax);
//  }

  // Heap-Objekt öffnen und Heap anlegen.
//  pTestData = (DL_VertexData*) sVertexHeap.Adr;

//  sVertexHeap.AnzDs++;
//  pTestData[sVertexHeap.AnzDs-1] = *oVertex;

//  // update MinMax with new vertex
//  iStat = UpdateMinMax( 0, *oVertex);

  return iStat;
}
//=============================================================================
int sstDxfPolylineCls::GetVertex(int            iKey,
                                 DL_VertexData *oVertex)
{
  DL_VertexData *pLocVertexArray;

  if ( iKey != 0) return -1;

  lActVertex++;

//  if (lActVertex > sVertexHeap.AnzDs) return -2;

//  pLocVertexArray = (DL_VertexData*) sVertexHeap.Adr;

  *oVertex = pLocVertexArray[lActVertex-1];
  return 0;
}
//=============================================================================
int sstDxfPolylineCls::ResetGet(int iKey)
{
  if ( iKey != 0) return -1;

  lActVertex = 0;
  return 0;
}
//=============================================================================
int sstDxfPolylineCls::ClearMemory(int iKey)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  // iStat = SST_HPO_Clear_c( 0, &sVertexHeap);

  lActVertex = 0;

  // iStat = ResetMinMax(0);

  return iStat;
}
//=============================================================================
int sstDxfPolylineCls::GetNumVertex(int iKey, unsigned long *lNumVertex)
{

  if ( iKey != 0) return -1;

  // *lNumVertex = sVertexHeap.AnzDs;

  return 0;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstDxfPolylineCls::WrtPLine2File (int           iKey,
                                      DL_Dxf      **dxf,
                                      DL_WriterA  **dw)
//-----------------------------------------------------------------------------
{
  unsigned long   lAnzDs=0;
  unsigned long   ii=0;
  DL_VertexData sVertex;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Die Anzahl der aktuell gespeicherten Datensätze zurückgeben.
  // iStat = DS1_DsAnz ( 0, sPntDss, &lAnzDs);
  iStat = (this)->GetNumVertex(0,&lAnzDs);

  (*dxf)->writePolyline(**dw, DL_PolylineData (lAnzDs,0,0,0),
                         DL_Attributes("mainlayer", 256, -1, "BYLAYER"));

  for (ii=1; ii<=lAnzDs; ii++)
  {
    // iStat = DS1_DsLesAbs ( 0, sPntDss, &sD3Pnt, ii);
    iStat = (this)->GetVertex(0,&sVertex);

    // (*dxf)->writeVertex( **dw, DL_VertexData(sD3Pnt.x, sD3Pnt.y, 0.0));
    (*dxf)->writeVertex( **dw, sVertex);
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
