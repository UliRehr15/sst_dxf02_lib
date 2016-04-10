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
// sstCsv2Dxf.h   11.03.16  Re.   11.03.16  Re.
//
// Datastructures and Prototypes for system "sstDxf01Lib"
//

#ifndef SST_CSV2DXF_HEADER
#define SST_CSV2DXF_HEADER

// Foreward definition
class sstDxf01DatabaseCls;

//==============================================================================
class sstCsv2DxfCls : public sstMisc01PrtFilCls
{
  public:   // Public functions
     sstCsv2DxfCls();  // Constructor
   //  ~sstDxf2CsvCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory  <BR>
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void testReading(char* file);
     void usage();
     // sstMisc01PrtFilCls oPrt; /**< output protocol file */
// ----------------------------------------------------------------------------
  private:  // Private functions
};
//-----------------------------------------------------------------------------

//==============================================================================
/**
* @brief Definition Class sstTestBaseInternCls
*
* template for sst base class <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstTemplateIntLib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf01WriteCls
{
  public:   // Public functions
     sstDxf01WriteCls(sstDxf01DatabaseCls *oDxfDB);  // Constructor
    ~sstDxf01WriteCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oTestBase.Func_1(iKey)
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int FileOpen (int         iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oTestBase.Func_1(iKey)
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int FileClose (int          iKey);
     //==============================================================================
     /**
     * @brief // Write dxf section header <BR>
     * iStat = oSstDxfWrite.WrtSecHeader(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecHeader (int         iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section layers <BR>
     * iStat = oSstDxfWrite.WrtSecLayers(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecLayers (int         iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section Blocks <BR>
     * iStat = oSstDxfWrite.WrtSecBlocks(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecBlocks (int         iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section Types <BR>
     * iStat = oSstDxfWrite.WrtSecTypes(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecTypes (int          iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Sectin Styles <BR>
     * iStat = oSstDxfWrite.WrtSecStyles(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecStyles (int          iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oSstDxfWrite.Func_1(iKey)
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecEntities (int          iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section objects <BR>
     * iStat = oSstDxfWrite.WrtSecObjects(iKey)
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecObjects (int          iKey);
     //==============================================================================
     /**
     * @brief // Write Polyline into section entities <BR>
     * iStat = oSstDxfWrite.WrtDss2Polyline(iKey,sPntDss);
     *
     * @param iKey    [in] For the moment 0
     * @param sPntDss [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtDss2PolyLine (int           iKey,
                          sstRec04Cls  *sPntDss);
// ----------------------------------------------------------------------------
private:  // Private functions
  DL_Dxf* dxf;     /**< dxflib dxf */
  DL_WriterA* dw;  /**< dxflib dw */
  sstDxf01DatabaseCls *oDxfDB; /**< sst dxf database */

};
//-----------------------------------------------------------------------------
//==============================================================================
/**
* @brief sst dxf database class
*
* Stores all dxf types <BR>
*
* Changed: 06.04.16  Re.
*
* @ingroup sstTemplateIntLib
*
* @author Re.
*
* @date 06.04.16
*/
// ----------------------------------------------------------------------------
class sstDxf01DatabaseCls
{
  public:   // Public functions
     sstDxf01DatabaseCls(sstMisc01PrtFilCls *oTmpPrt);  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Read all Csv Files into dxf database <BR>
     * iStat = oSstDxfDB.ReadAllCsvFiles(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadAllCsvFiles(int iKey, std::string oDxfFilNam);
// ----------------------------------------------------------------------------
     sstDxf01FncLayCls* getSstFncLay();
     void setSstFncLay(const sstDxf01FncLayCls &value);

     sstDxf01FncBlkCls* getSstFncBlk();
     void setSstFncBlk(const sstDxf01FncBlkCls &value);

     sstDxf01FncArcCls* getSstFncArc();
     void setSstFncArc(const sstDxf01FncArcCls &value);

     sstDxf01FncInsertCls* getSstFncInsert();
     void setSstFncInsert(const sstDxf01FncInsertCls &value);

private:  // Private functions
     sstDxf01FncLayCls oSstFncLay;        /**< layer recmem object */
     sstDxf01FncBlkCls oSstFncBlk;        /**< Block recmem object */
  sstDxf01FncArcCls oSstFncArc;        /**< Arc recmem object */
  sstDxf01FncInsertCls oSstFncInsert;  /**< Insert recmem object */
  sstMisc01PrtFilCls *oPrt;            /**< Protocol object */

};
//-----------------------------------------------------------------------------


#endif // SSTDXF2CSV_H

