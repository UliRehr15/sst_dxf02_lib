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
// sstDxf02Lib.h   22.02.16  Re.   22.02.16  Re.
//
// Datastructures and Prototypes for system "sstDxf02Lib"
//
  
#ifndef   _SST_DXF02LIB_HEADER
#define   _SST_DXF02LIB_HEADER

/**
 * @defgroup sstDxf02Lib sstDxf02Lib: cpp sst dxf library (Version 2)
 *
 * cpp sst dxf library <BR>
 *
 */


#define dSSTDXFLAYERNAMELEN   256  /**< Layer Name length @ingroup sstDxf02Lib */
#define dSSTDXFBLOCKNAMELEN   256  /**< Block Name length @ingroup sstDxf02Lib */
#define dSSTDXFLTYPENAMELEN   256  /**< LineType Name length @ingroup sstDxf02Lib */

//==============================================================================
/**
* @brief Definition Class sstDxf02EntityTypeCls
*
* Classes and functions for LibreCAD enum EntityType <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf02EntityTypeCls
{
  public:   // Public functions
     sstDxf02EntityTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // converts enum to string <BR>
     * oString = oEntityType.Enum2String(eType);
     *
     * @param eType [in] For the moment 0
     *
     * @return Type as string
     */
     // ----------------------------------------------------------------------------
     std::string Enum2String(RS2::EntityType eType);
     //==============================================================================
     /**
     * @brief // converts string to enum <BR>
     * eType = oEntityType.String2Enum(oTypeString);
     *
     * @param oTypeString [in] Entity as string
     *
     * @return Type as librecad enum
     */
     // ----------------------------------------------------------------------------
     RS2::EntityType String2Enum(std::string oTypeString);
// ----------------------------------------------------------------------------
private:  // Private functions
int Dum;        /**< Dummy */
};
//==============================================================================
/**
* @brief sst dxf base class for dxf types
*
* More Comment
*
* Changed: 03.03.16  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 03.03.16
**/
//------------------------------------------------------------------------
class sstDxf02TypBaseCls
{
  public:
    sstDxf02TypBaseCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getColor() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setColor(int value);
    //==============================================================================
    /**
    * @brief // read attribu data from dxflib arc <BR>
    * oSstDxfArc.BaseReadFromDL(oDLAttrib);
    *
    * @param oDLAttrib [in] dxflib attribut structure
    */
    // ----------------------------------------------------------------------------
    void BaseReadFromDL(const DL_Attributes oDLAttrib);
    //==============================================================================
    /**
    * @brief // write attribute data to dxflib attribut <BR>
    * oSstDxfBase.BaseWritToDL(poDLAttrib);
    *
    * @param poDLAttrib [out] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void BaseWritToDL(DL_Attributes *poDLAttrib);

    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getBlockID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setBlockID(const dREC04RECNUMTYP &value);

    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getLayerID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setLayerID(const dREC04RECNUMTYP &value);

    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getLinetypeID() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setLinetypeID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getColor24() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setColor24(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getWidth() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setWidth(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getHandle() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setHandle(int value);
    //==============================================================================

private:
    // standard attributes
    dREC04RECNUMTYP dRecordID;  /**< Identifier in Element table */
    dREC04RECNUMTYP dLayerID;    /**< Identifier in Layer table */
    dREC04RECNUMTYP dBlockID;    /**< Identifier in Block table */
    dREC04RECNUMTYP dLinetypeID; /**< Identifier in Linetype table */
    int color;                   /**< color */
    int color24;                 /**< color24 */
    int width;                   /**< width */
    int handle;                  /**< handle */
};
//==============================================================================
/**
* @brief LineType record class
*
* LineType record class <BR>
*
* Changed: 10.06.16  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 10.06.16
*/
// ----------------------------------------------------------------------------
class sstDxf02TypLTypeCls
{
  public:   // Public functions
     sstDxf02TypLTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Set Linetype name <BR>
     * oSstDxfLType.setName(iKey)
     *
     * @param oName [in] Set Name
     */
     // ----------------------------------------------------------------------------
     void setName(const std::string oName);
     //==============================================================================
     /**
     * @brief // Get LineType Name <BR>
     * oSstDxfLType.getName(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Get Size of Linetype Name <BR>
     * iSizeNam = oSstDxfLType.GetSizeName();
     *
     * @return int size of name
     */
     // ----------------------------------------------------------------------------
     int getSizeName() const;
     //==============================================================================
     /**
     * @brief // Get Linetype ID <BR>
     * dLineTypeID = oSstDxfLType.GetLineTypeID();
     *
     * @return Linetype ID
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getLineTypeID() const;
     //==============================================================================
     /**
     * @brief // Set Linetype ID <BR>
     * oSstDxfLType.setLineTypeID(value);
     *
     * @param value [in] Linetype ID
     */
     // ----------------------------------------------------------------------------
     void setLineTypeID(const dREC04RECNUMTYP &value);
     //==============================================================================

private:  // Private functions
     dREC04RECNUMTYP dLineTypeID;   /**< Linetype ID */
     char Nam[dSSTDXFLTYPENAMELEN]; /**< Linetype Name */
};
//==============================================================================
/**
* @brief sst Dxf Arc Class
*
* More Comment
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf02TypArcCls : public sstDxf02TypBaseCls
{
  public:
    sstDxf02TypArcCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfArc.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // read arc data from dxflib arc <BR>
    * oSstDxfArc.ReadFromDL(poDLArc);
    *
    * @param poDLArc [in] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_ArcData poDLArc);
    //==============================================================================
    /**
    * @brief // write arc data to dxflib arc <BR>
    * oSstDxfArc.WritToDL(poDLArc);
    *
    * @param poDLArc [out] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_ArcData *poDLArc);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCx() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCx(double value);

    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCy() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCy(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCz() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCz(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getRadius() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setRadius(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getAngle1() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setAngle1(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getAngle2() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setAngle2(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID  <BR>
    *
    * @return LayerID
    */
    // ----------------------------------------------------------------------------
    unsigned long getLayerID() const;
    //==============================================================================
    /**
    * @brief // Set Layer ID  <BR>
    *
    * @param value [in] Set Layer ID
    */
    // ----------------------------------------------------------------------------
    void setLayerID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Block ID  <BR>
    *
    * @return BlockID
    */
    // ----------------------------------------------------------------------------
    unsigned long getBlockID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setBlockID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    unsigned long getArcID() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setArcID(unsigned long value);
    //==============================================================================

private:
    dREC04RECNUMTYP ulArcID;
    dREC04RECNUMTYP ulLayerID;
    dREC04RECNUMTYP ulBlockID;
    double cx;
    double cy;
    double cz;
    double radius;
    double angle1;
    double angle2;
};
//==============================================================================//==============================================================================
/**
* @brief sst Dxf insert Class
*
* storable insert record
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf02TypInsertCls : public sstDxf02TypBaseCls
{
  public:
    sstDxf02TypInsertCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill Insert record from dxflib insert <BR>
    * oSstDxfInsert.ReadFromDL(poDLInsert);
    *
    * @param poDLInsert [in] dxflib Insert structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_InsertData poDLInsert);
    //==============================================================================
    /**
    * @brief // write Insert record data to dxflib insert <BR>
    * oSstDxfInsert.WritToDL(poDLInsert);
    *
    * @param poDLInsert [out] dxflib insert structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_InsertData *poDLInsert);
    //==============================================================================
    /**
    * @brief // Get Layer ID  <BR>
    *
    * @return LayerID
    */
    // ----------------------------------------------------------------------------
    unsigned long getLayerID() const;
    //==============================================================================
    /**
    * @brief // Set Layer ID  <BR>
    *
    * @param value [in] Set Layer ID
    */
    // ----------------------------------------------------------------------------
    void setLayerID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Block ID  <BR>
    *
    * @return BlockID
    */
    // ----------------------------------------------------------------------------
    unsigned long getBlockID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setBlockID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get insert ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    unsigned long getInsertID() const;
    //==============================================================================
    /**
    * @brief // Set insert ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setInsertID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get insert ipx  <BR>
    *
    * @return double ipx
    */
    // ----------------------------------------------------------------------------
    double getIpx() const;
    //==============================================================================
    /**
    * @brief // Set insert ipx  <BR>
    *
    * @param value [in] ipx
    */
    // ----------------------------------------------------------------------------
    void setIpx(double value);
    //==============================================================================
    /**
    * @brief // Get insert ipy  <BR>
    *
    * @return double ipy
    */
    // ----------------------------------------------------------------------------
    double getIpy() const;
    //==============================================================================
    /**
    * @brief // Set insert ipy  <BR>
    *
    * @param value [in] ipy
    */
    // ----------------------------------------------------------------------------
    void setIpy(double value);
    //==============================================================================
    /**
    * @brief // Get insert ipz <BR>
    *
    * @return double ipz
    */
    // ----------------------------------------------------------------------------
    double getIpz() const;
    //==============================================================================
    /**
    * @brief // Set insert ipz  <BR>
    *
    * @param value [in] ipz
    */
    // ----------------------------------------------------------------------------
    void setIpz(double value);
    // sstDxf02TypBaseCls getBaseAttributes();

private:

    unsigned long ulInsertID; // record number of Insert
    unsigned long ulLayerID;  // record number of Layer
    unsigned long ulBlockID;  // record number of Block

    /*! Name of the referred block. */
    // std::string name;
    /*! X Coordinate of insertion point. */
    double ipx;
    /*! Y Coordinate of insertion point. */
    double ipy;
    /*! Z Coordinate of insertion point. */
    double ipz;
    /*! X Scale factor. */
    double sx;
    /*! Y Scale factor. */
    double sy;
    /*! Z Scale factor. */
    double sz;
    /*! Rotation angle in degrees. */
    double angle;
    /*! Number of colums if we insert an array of the block or 1. */
    int cols;
    /*! Number of rows if we insert an array of the block or 1. */
    int rows;
    /*! Values for the spacing between cols. */
    double colSp;
    /*! Values for the spacing between rows. */
    double rowSp;
};
//==============================================================================
/**
* @brief sst Dxf Hatch Class
*
* storable hatch record
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf02TypHatchCls : public sstDxf02TypBaseCls
{
  public:
    sstDxf02TypHatchCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfHatch.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill Hatch record from dxflib hatch <BR>
    * oSstDxfHatch.ReadFromDL(poDLHatch);
    *
    * @param poDLHatch [in] dxflib Hatch structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_HatchData poDLHatch);
    //==============================================================================
    /**
    * @brief // write Hatch record data to dxflib hatch <BR>
    * oSstDxfHatch.WritToDL(poDLHatch);
    *
    * @param poDLHatch [out] dxflib hatch structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_HatchData *poDLHatch);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    int getNumLoops() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setNumLoops(int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    bool getSolid() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setSolid(bool value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getScale() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setScale(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getAngle() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setAngle(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getPatternID() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setPatternID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getOriginX() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setOriginX(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getOriginY() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setOriginY(double value);
    //==============================================================================

private:
    int numLoops; /*! Number of boundary paths (loops). */
    bool solid; /*! Solid fill flag (true=solid, false=pattern). */
    double scale;  /*! Pattern scale or spacing */
    double angle;  /*! Pattern angle in degrees */
    // std::string pattern;
    dREC04RECNUMTYP dPatternID;  /*! Pattern name. */
    double originX;  /*! Pattern origin */
    double originY;  /*! Pattern origin */
};
//==============================================================================
/**
* @brief sst Dxf Hatch Edge Class
*
* storable hatch edge record
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf02TypHatchEdgeCls  // : public sstDxf02TypBaseCls
{
  public:
    sstDxf02TypHatchEdgeCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill hatch edge record from dxflib hatch edge <BR>
    * oSstDxfHatchEdge.ReadFromDL(poDLHatchEdge);
    *
    * @param poDLHatchEdge [in] dxflib Hatch edge structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_HatchEdgeData poDLHatchEdge);
    //==============================================================================
    /**
    * @brief // write hatch edge record data to dxflib hatch edge <BR>
    * oSstDxfHatchEdge.WritToDL(poDLHatchEdge);
    *
    * @param poDLHatchEdge [out] dxflib hatch edge structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_HatchEdgeData *poDLHatchEdge);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getDefined() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDefined(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getType() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setType(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getX1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setX1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getY1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setY1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getX2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setX2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getY2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setY2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getCx() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCx(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getCy() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCy(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getRadius() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setRadius(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getAngle1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setAngle1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getAngle2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setAngle2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getCcw() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCcw(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getMx() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setMx(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getMy() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setMy(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getRatio() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setRatio(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getDegree() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDegree(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getRational() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setRational(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getPeriodic() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setPeriodic(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getNKnots() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNKnots(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getNControl() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNControl(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getNFit() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNFit(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getStartTangentX() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setStartTangentX(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getStartTangentY() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setStartTangentY(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getEndTangentX() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setEndTangentX(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getEndTangentY() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setEndTangentY(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getParentID() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setParentID(const dREC04RECNUMTYP &value);
    //==============================================================================

private:
    dREC04RECNUMTYP dRecordID; /**< record id */
    dREC04RECNUMTYP dParentID; /**< Parent id */
    bool defined;  //  * Set to true if this edge is fully defined.
    int type;   // * Edge type. 1=line, 2=arc, 3=elliptic arc, 4=spline.
    double x1;  /*! Start point (X). */
    double y1;  /*! Start point (Y). */
    double x2;  /*! End point (X). */
    double y2;  /*! End point (Y). */
    double cx;  /*! Center point of arc or ellipse arc (X). */
    double cy;  /*! Center point of arc or ellipse arc (Y). */
    double radius;  /*! Arc radius. */
    double angle1;  /*! Start angle of arc or ellipse arc. */
    double angle2;  /*! End angle of arc or ellipse arc. */
    bool ccw;  /*! Counterclockwise flag for arc or ellipse arc. */
    double mx;  /*! Major axis end point (X). */
    double my;  /*! Major axis end point (Y). */
    double ratio;  /*! Axis ratio */
    unsigned int degree;  /*! Spline degree */
    bool rational;
    bool periodic;
    unsigned int nKnots;  /*! Number of knots. */
    unsigned int nControl;  /*! Number of control points. */
    unsigned int nFit;  /*! Number of fit points. */
    double startTangentX;
    double startTangentY;
    double endTangentX;
    double endTangentY;
};
//==============================================================================
/**
* @brief sst Dxf Hatch Loop Class
*
* storable hatch Loop record
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf02TypHatchLoopCls // : public sstDxf02TypBaseCls
{
  public:
    sstDxf02TypHatchLoopCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill hatch loop record from dxflib hatch loop <BR>
    * oSstDxfHatchLoop.ReadFromDL(poDLHatchLoop);
    *
    * @param poDLHatchLoop [in] dxflib hatch loop structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_HatchLoopData poDLHatchLoop);
    //==============================================================================
    /**
    * @brief // write Hatch loop record data to dxflib hatch loop <BR>
    * oSstDxfHatchLoop.WritToDL(poDLHatchLoop);
    *
    * @param poDLHatchLoop [out] dxflib hatch loop structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_HatchLoopData *poDLHatchLoop);
    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getNumEdges() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNumEdges(int value);
    //==============================================================================

private:
    dREC04RECNUMTYP dRecordID; /**< record id */
    int numEdges;               /**< numEdges */

};
//==============================================================================
/**
* @brief sst Dxf Polyline Class
*
* storable polyline record
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf02TypPolylineCls : public sstDxf02TypBaseCls
{
  public:
    sstDxf02TypPolylineCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill polyline record from dxflib polyline <BR>
    * oSstDxfPolyline.ReadFromDL(poDLPolyline);
    *
    * @param poDLPolyline [in] dxflib polyline structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_PolylineData poDLPolyline);
    //==============================================================================
    /**
    * @brief // write polyline record data to dxflib polyline <BR>
    * oSstDxfPolyline.WritToDL(poDLPolyline);
    *
    * @param poDLPolyline [out] dxflib polyline structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_PolylineData *poDLPolyline);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    unsigned int getNumber() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setNumber(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    unsigned int getM() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setM(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    unsigned int getN() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setN(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    int getFlags() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setFlags(int value);
    //==============================================================================

private:

    unsigned int number;  /*! Number of vertices in this polyline. */
    unsigned int m;  /*! Number of vertices in m direction if polyline is a polygon mesh. */
    unsigned int n;  /*! Number of vertices in n direction if polyline is a polygon mesh. */
    int flags;  /*! Flags */
};
//==============================================================================
/**
* @brief sst Dxf Vertex Class
*
* storable vertex record
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf02TypVertexCls // : public sstDxf02TypBaseCls
{
  public:
    sstDxf02TypVertexCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill vertex record from dxflib vertex <BR>
    * oSstDxfVertex.ReadFromDL(poDLVertex);
    *
    * @param poDLVertex [in] dxflib Vertex structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_VertexData poDLVertex);
    //==============================================================================
    /**
    * @brief // write vertex record data to dxflib vertex <BR>
    * oSstDxfVertex.WritToDL(poDLVertex);
    *
    * @param poDLVertex [out] dxflib vertex structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_VertexData *poDLVertex);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getParentID() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setParentID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    RS2::EntityType getEntityType() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setEntityType(const RS2::EntityType &value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getX() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setX(double value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getY() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setY(double value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getZ() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setZ(double value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getBulge() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setBulge(double value);

private:
    dREC04RECNUMTYP dRecordID; /**< ID of vertex */
    dREC04RECNUMTYP dParentID; /**< ID of parent object */
    RS2::EntityType eEntityType;     /**< Polyline and so on ... */
    double x;  /*! X Coordinate of the vertex. */
    double y;  /*! Y Coordinate of the vertex. */
    double z;  /*! Z Coordinate of the vertex. */
    double bulge;  /*! Bulge of vertex. (The tangent of 1/4 of the arc angle or 0 for lines) */
};
//==============================================================================
/**
* @brief sst Dxf Layer Class
*
* template for sst base class <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf02TypLayCls : public sstDxf02TypBaseCls
{
  public:   // Public functions
     sstDxf02TypLayCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Set Layer name <BR>
     * oSstDxfLay.setName(iKey)
     *
     * @param cName [in] Set Name
     */
     // ----------------------------------------------------------------------------
     void setName(const char* cName);
     //==============================================================================
     /**
     * @brief // Get Layer Name <BR>
     * oSstDxfLay.getName(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @return int flags
     */
     // ----------------------------------------------------------------------------
     int getFlags() const;
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @param value [in] Flags
     */
     // ----------------------------------------------------------------------------
     void setFlags(int value);
     //==============================================================================
     /**
     * @brief // Set Test Data <BR>
     * iStat= oSstDxfLay.SetTestData(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetTestData(int iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.ReadFromDL(poDLArc);
     *
     * @param poDlLay [in] dxflib Layer structure
     */
     void ReadFromDL(const DL_LayerData poDlLay);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.WritToDL(poDLArc);
     *
     * @param poDlLay [out] dxflib layer structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     void WritToDL(DL_LayerData *poDlLay);
     //==============================================================================
     /**
     * @brief // Get Layer ID <BR>
     * ulLayerID = oSstDxfLay.GetLayerID();
     *
     * @return unsigned long Layer ID
     */
     // ----------------------------------------------------------------------------
     unsigned long getLayerID() const;
     //==============================================================================
     /**
     * @brief // Set Layer ID <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @param value [in] Layer ID
     */
     // ----------------------------------------------------------------------------
     void setLayerID(unsigned long value);
     //==============================================================================
     /**
     * @brief // Get Size of Layer Name <BR>
     * iSizeNam = oSstDxfLay.GetSizeName();
     *
     * @return int size of name
     */
     // ----------------------------------------------------------------------------
     int getSizeName() const;
     //==============================================================================

  private:  // Private functions
    unsigned long ulLayerID;
    int flags;               /**< Layer flags. (1 = frozen, 2 = frozen by default, 4 = locked) */
    char Nam[dSSTDXFLAYERNAMELEN]; /**< Layer Name */

};
//==============================================================================
/**
* @brief sst Dxf Block Class
*
* template for sst base class <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf02TypBlkCls : public sstDxf02TypBaseCls
{
  public:   // Public functions
     sstDxf02TypBlkCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param cName [in] For the moment 0
     */
     // ----------------------------------------------------------------------------
     void setName(const char* cName);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return int flags
     */
     // ----------------------------------------------------------------------------
     int getFlags() const;
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param value [in] Flags
     */
     // ----------------------------------------------------------------------------
     void setFlags(int value);
     //==============================================================================
     /**
     * @brief // Set Test Data <BR>
     * iStat= oSstDxfBlk.SetTestData(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetTestData(int iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.ReadFromDL(poDlBlk);
     *
     * @param poDlBlk [in] dxflib arc structure
     */
     void ReadFromDL(const DL_BlockData poDlBlk);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.WritToDL(poDlBlk);
     *
     * @param poDlBlk [out] dxflib arc structure
     */
     void WritToDL(DL_BlockData *poDlBlk);
     //==============================================================================
     /**
     * @brief // Get Block ID <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return unsigned long ulBlockID
     */
     // ----------------------------------------------------------------------------
     unsigned long getBlockID() const;
     //==============================================================================
     /**
     * @brief // Set Block ID <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param value [in] Block ID
     */
     // ----------------------------------------------------------------------------
     void setBlockID(unsigned long value);
     //==============================================================================

     char Nam[dSSTDXFBLOCKNAMELEN];  /**< Block Name */
  private:  // Private functions
     unsigned long ulBlockID;
     int  flags;               /**< Block Flags */
};
//==============================================================================
/**
* @brief Base Class for sst DXF function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncBaseCls: public sstRec04Cls
{
  public:
  //==============================================================================
  /**
  * @brief // constructor with record size <BR>
  *
  * @param iSize [in] Record size
  */
  // ----------------------------------------------------------------------------
    sstDxf02FncBaseCls(dREC04RECSIZTYP iSize);  // Constructor
    //==============================================================================
    /**
    * @brief // read base attribute data from csv string to base object <BR>
    * iStat = oDxfFncBase.Csv_BaseRead( iKey, oErrStr, oCsvArcStr, oArc);
    *
    * @param iKey         [in]  For the moment 0
    * @param oErrStr      [out] string where interpret error occors
    * @param oCsvBaseStr  [in]  Csv Arc string
    * @param oAttributes  [out] return base dxf attribute object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseRead(int iKey, std::string *oErrStr, std::string *oCsvBaseStr, sstDxf02TypBaseCls *oAttributes);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncArc.Func_1(iKey)
    *
    * @param iKey           [in] For the moment 0
    * @param oAttributes   [in] base dxf attributes
    * @param ssstDxfLib_Str [out] csv string with base dxf attributes
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseWrite(int iKey, sstDxf02TypBaseCls oAttributes, std::string *ssstDxfLib_Str);
    //==============================================================================
    /**
    * @brief // write base attribtes titel row to csv file <BR>
    * iStat = oDxfFncBase.Csv_BaseHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseHeader(int iKey, std::string *oCsvStr);

    sstStr01Cls oCsvRow;   /**< Csv String Convert object */
  private:
};
//==============================================================================
/**
* @brief LineType table class
*
* LineType table class <BR>
*
* Changed: 10.06.16  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 10.06.16
*/
// ----------------------------------------------------------------------------
class sstDxf02FncLTypeCls : public sstDxf02FncBaseCls
{
  public:   // Public functions
     sstDxf02FncLTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // write new record to table if unique LType name <BR>
     * iStat = oLTypeTab.WriteNewUnique(iKey);
     *
     * @param iKey      [in] For the moment 0
     * @param oLTypeRec [in] LType Record
     * @param dLTypeRecNo [out] new LType Record number
     *
     * @return Errorstate
     *
     * @retval   = 1: New record written
     * @retval   = 0: name already in table, not written
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteNewUnique(int iKey,sstDxf02TypLTypeCls oLTypeRec, dREC04RECNUMTYP *dLTypeRecNo);
     //==============================================================================
     /**
     * @brief // Read line type object from string row <BR>
     * iStat = oSstFncLType.CsvRead ( iKey, oErrStr, oRowStr, oSstLay);
     *
     * @param iKey     [in]  For the moment 0
     * @param oErrStr  [out] Read Error at string part
     * @param oRowStr  [in]  read row
     * @param oSstLType  [out] result line type object
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Read(int                iKey,
                  std::string       *oErrStr,
                  std::string       *oRowStr,
                  sstDxf02TypLTypeCls *oSstLType);  // Csv Read Function
     //==============================================================================
     /**
     * @brief // Write linr type object to row string <BR>
     * iStat = oSstFncLType.Csv_Write ( iKey, oSstLType, oRowStr);
     *
     * @param iKey    [in] For the moment 0
     * @param oSstLType [in] Layer object
     * @param sRowStr [out] Result Row string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Write(int                iKey,
                   sstDxf02TypLTypeCls *oSstLType,
                   std::string       *sRowStr);
     //==============================================================================
     /**
     * @brief // write Layer titel row to csv file <BR>
     * iStat = oSstFncLay.Csv_WriteHeader ( 0, &oCsvStr)
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] return string titel row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_WriteHeader(int iKey, std::string *oCsvStr);
     //==============================================================================
     /**
     * @brief // Return Linetype name sorting key <BR>
     * poNameSortKey = oSstFncLType.GetNameSortKey();
     *
     * @return LType Name sorting key
     */
     // ----------------------------------------------------------------------------
     sstRec04TreeKeyCls* getNameSortKey();
     //==============================================================================
     /**
     * @brief // Read whole linetype csv file into sst_rec_mem <BR>
     * iStat = oSstFncLType.ReadCsvFile ( iKey, oFilNam);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name to import to rec mem
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Open File Error
     * @retval   = -3: General read error
     * @retval   = -4: Record format read Error
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadCsvFile(int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // write whole linetype data from table to csv file  <BR>
     * iStat = oDxfFncLType.WriteCsvFile ( iKey, oDxfFilNam);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] File name to export to csv file
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     */
     // ----------------------------------------------------------------------------
     int WriteCsvFile(int iKey, std::string oDxfFilNam);
     //==============================================================================


// ----------------------------------------------------------------------------
  private:  // Private functions
     sstRec04TreeKeyCls oLTypeTree; /**< sort tree for linetype names in table */
};
//==============================================================================
/**
* @brief Definition Class sstDxf02FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncArcCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncArcCls();  // Constructor
    //==============================================================================
    /**
    * @brief // read arc data from csv string to arc object <BR>
    * iStat = oDxfFncArc.Csv_Read( iKey, oErrStr, oCsvArcStr, oArc);
    *
    * @param iKey       [in]  For the moment 0
    * @param oErrStr    [out] string where interpret error occors
    * @param oCsvArcStr [in]  Csv Arc string
    * @param oArc       [out] return arc object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *oErrStr,
                 std::string       *oCsvArcStr,
                 sstDxf02TypArcCls *oArc);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncArc.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param osstDxf02TypArcCls [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int iKey,
                  sstDxf02TypArcCls *osstDxf02TypArcCls,
                  std::string *ssstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oDxfFncArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oDxfFncArc.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole arc data from table to csv file  <BR>
    * iStat = oSstFncArc.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Definition Class sstDxf02FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncInsertCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncInsertCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oCsvInsert.Csv_Read(iKey, oErrStr, oString, oDxfInsert);
    *
    * @param iKey [in] For the moment 0
    * @param sErrTxt [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    * @param osstDxf02TypArcCls [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int iKey,
                 std::string *sErrTxt,
                 std::string *ssstDxfLib_Str,
                 sstDxf02TypInsertCls *osstDxf02TypArcCls);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oCsvArc.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param osstDxf02TypArcCls [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int iKey,
                  sstDxf02TypInsertCls *osstDxf02TypArcCls,
                  std::string *ssstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole insert data from table to csv file  <BR>
    * iStat = oDxfFncInsert.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncHatchCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncHatchCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncHatch.Csv_Read(iKey, oErrStr, oCsvHatchStr, oHatch);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvHatchStr [in] For the moment 0
    * @param oHatch       [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                  iKey,
                 std::string         *oErrStr,
                 std::string         *oCsvHatchStr,
                 sstDxf02TypHatchCls *oHatch);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncHatch.Csv_Write ( iKey, oHatch, oCsvHatchStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oHatch       [in] For the moment 0
    * @param oCsvHatchStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                  iKey,
                  sstDxf02TypHatchCls *oHatch,
                  std::string         *oCsvHatchStr);
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncHatchEdgeCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncHatchEdgeCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncHEdge.Csv_Read(iKey, oErrStr, oCsvHEdgeStr, oHatchEdge);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvHEdgeStr [in] For the moment 0
    * @param oHatchEdge   [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                      iKey,
                 std::string             *oErrStr,
                 std::string             *oCsvHEdgeStr,
                 sstDxf02TypHatchEdgeCls *oHatchEdge);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncHEdge.Csv_Write ( iKey, oHatchEdge, oCsvHEdgeStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oHatchEdge   [in] For the moment 0
    * @param oCsvHEdgeStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                      iKey,
                  sstDxf02TypHatchEdgeCls *oHatchEdge,
                  std::string             *oCsvHEdgeStr);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncHatchLoopCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncHatchLoopCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncHLoop.Csv_Read(iKey, oErrStr, oCsvHLoopStr, oHatchLoop);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvHLoopStr [in] For the moment 0
    * @param oHatchLoop   [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                      iKey,
                 std::string             *oErrStr,
                 std::string             *oCsvHLoopStr,
                 sstDxf02TypHatchLoopCls *oHatchLoop);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncHLoop.Csv_Write ( iKey, oHatchLoop, oCsvHLoopStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oHatchLoop   [in] For the moment 0
    * @param oCsvHLoopStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                      iKey,
                  sstDxf02TypHatchLoopCls *oHatchLoop,
                  std::string             *oCsvHLoopStr);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncPolylineCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncPolylineCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncPLine.Csv_Read(iKey, oErrStr, oCsvPLineStr, oPolyline);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvPLineStr [in] For the moment 0
    * @param oPolyline    [out] Polyline
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                     iKey,
                 std::string            *oErrStr,
                 std::string            *oCsvPLineStr,
                 sstDxf02TypPolylineCls *oPolyline);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncPline.Csv_Write ( iKey, oPolyline, oCsvPlineStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oPolyline    [in] For the moment 0
    * @param oCsvPLineStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                     iKey,
                  sstDxf02TypPolylineCls *oPolyline,
                  std::string            *oCsvPLineStr);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncVertexCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncVertexCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncVertex.Csv_Read(iKey, oErrStr, oCsvVertexStr, oVertex);
    *
    * @param iKey          [in] For the moment 0
    * @param oErrStr       [in] For the moment 0
    * @param oCsvVertexStr [in] For the moment 0
    * @param oVertex       [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                   iKey,
                 std::string          *oErrStr,
                 std::string          *oCsvVertexStr,
                 sstDxf02TypVertexCls *oVertex);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // write Vertex object to csv string <BR>
    * iStat = oDxfFncVertex.Csv_Write ( iKey, oVertex, oCsvVertexStr);
    *
    * @param iKey          [in] For the moment 0
    * @param oVertex       [in] For the moment 0
    * @param oCsvVertexStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                   iKey,
                  sstDxf02TypVertexCls *oVertex,
                  std::string          *oCsvVertexStr);
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Definition Class sstDxf02FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncLayCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncLayCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Return Layer name sorting key <BR>
    * poNameSortKey = oSstFncLay.Func_1();
    *
    * @return Layer Name sorting key
    */
    // ----------------------------------------------------------------------------
    sstRec04TreeKeyCls* getNameSortKey();
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole layer data from table to csv file  <BR>
    * iStat = oDxfFncLayer.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
    /**
    * @brief // Read layer object from string row <BR>
    * iStat = oSstFncLay.CsvRead ( iKey, oErrStr, oRowStr, oSstLay);
    *
    * @param iKey     [in]  For the moment 0
    * @param oErrStr  [out] Read Error at string part
    * @param oRowStr  [in]  read row
    * @param oSstLay  [out] result layer object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *oErrStr,
                 std::string       *oRowStr,
                 sstDxf02TypLayCls *oSstLay);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Write layer object to row string <BR>
    * iStat = oSstFncLay.Csv_Write ( iKey, oSstLay, oRowStr);
    *
    * @param iKey    [in] For the moment 0
    * @param oSstLay [in] Layer object
    * @param sRowStr [out] Result Row string
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                iKey,
                  sstDxf02TypLayCls *oSstLay,
                  std::string       *sRowStr);
    //==============================================================================
    /**
    * @brief // write Layer titel row to csv file <BR>
    * iStat = oSstFncLay.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
  private:
    sstRec04TreeKeyCls oLayerTree; /**< sort tree for layers names in table */

};
//==============================================================================
/**
* @brief Definition Class sstDxf02FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf02FncBlkCls : public sstDxf02FncBaseCls
{
  public:
    sstDxf02FncBlkCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Return Block name sorting key <BR>
    * poNameSortKey = oSstFncBlk.Func_1();
    *
    * @return Block Name sorting key
    */
    // ----------------------------------------------------------------------------
    sstRec04TreeKeyCls* getNameSortKey();
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param sErrTxt [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    * @param oSstDxf01TypBlk [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *sErrTxt,
                 std::string       *sSstDxfLib_Str,
                 sstDxf02TypBlkCls *oSstDxf01TypBlk);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param oSstDxf01TypBlk [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                iKey,
                  sstDxf02TypBlkCls *oSstDxf01TypBlk,
                  std::string       *sSstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
    sstRec04TreeKeyCls oBlockTree; /**< sort tree for block names in table */
};

//==============================================================================
/**
* @brief dxf main record for storing in record memory
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf02TypMainCls
{
  public:   // Public functions
     sstDxf02TypMainCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getMainID() const;
     //==============================================================================
     /**
     * @brief // Set record number in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param dValue [in] main record number
     */
     // ----------------------------------------------------------------------------
     void setMainID(const dREC04RECNUMTYP &dValue);
     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     std::string getSectString() const;
     //==============================================================================
     /**
     * @brief // Set section string B or L in csv file <BR>
     * oDxfMainRec.SetSectString(oSectString);
     *
     * @param oSectString [in] section string B or L
     */
     // ----------------------------------------------------------------------------
     void setSectString(const std::string &oSectString);

     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getLayBlockID() const;
     //==============================================================================
     /**
     * @brief // Set record number of block or layer in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param dValue [in] main record number
     */
     // ----------------------------------------------------------------------------
     void setLayBlockID(const dREC04RECNUMTYP &dValue);
     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     RS2::EntityType getEntityType() const;
     //==============================================================================
     /**
     * @brief // Set entity type in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param eValue [in] entity type
     */
     // ----------------------------------------------------------------------------
     void setEntityType(const RS2::EntityType &eValue);

     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getTypeID() const;
     //==============================================================================
     /**
     * @brief // Set record number in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param dValue [in] main record number
     */
     // ----------------------------------------------------------------------------
     void setTypeID(const dREC04RECNUMTYP &dValue);

private:  // Private functions
  dREC04RECNUMTYP   dMainID;      /**< Record number in this main file */
  char              cSectionType[2];  /**< L or B */
  dREC04RECNUMTYP   dLayBlockID;   /**< Record number in Layer or block file */
//   char cElementType[16];         /**< ARC. CIRCE, LINE, VERTEX and so on ... */
  RS2::EntityType   eEntityType;     /**< ARC. CIRCE, LINE, VERTEX and so on ... */
  dREC04RECNUMTYP   dTypeID;          /**< Record number in type file */

};
//==============================================================================
/**
* @brief Function class for dxf main record
*
* number; Section; numSect;  Type; numType;  <BR>
*      1;       B;    567;    Arc;     234;  <BR>
*
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
class sstDxf02FncMainCls : public sstDxf02FncBaseCls
{
  public:   // Public functions
     sstDxf02FncMainCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oCsvArc.Func_1(iKey)
     *
     * @param iKey [in] For the moment 0
     * @param sErrTxt [in] For the moment 0
     * @param ssstDxfLib_Str [in] For the moment 0
     * @param osstDxf02TypMainCls [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Read(int iKey,
                  std::string *sErrTxt,
                  std::string *ssstDxfLib_Str,
                  sstDxf02TypMainCls *osstDxf02TypMainCls);  // Csv Read Function
     //==============================================================================
     /**
     * @brief // convert dxf main record into csv string <BR>
     * iStat = oCsvMain.Csv_Write(iKey, oMainRec, oMainStr);
     *
     * @param iKey        [in] For the moment 0
     * @param oMainRec    [in] sst dxf main record
     * @param oMainCsvStr [out] result string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Write(int                 iKey,
                   sstDxf02TypMainCls *oMainRec,
                   std::string        *oMainCsvStr);
     //==============================================================================
     /**
     * @brief // write ARC titel row to csv file <BR>
     * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] return string titel row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_WriteHeader(int iKey, std::string *oCsvStr);
     //==============================================================================
     /**
     * @brief // Read whole layer csv file into sst_rec_mem <BR>
     * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name to import to rec mem
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Open File Error
     * @retval   = -3: General read error
     * @retval   = -4: Record format read Error
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadCsvFile(int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // write whole main data from table to csv file  <BR>
     * iStat = oDxfFncMain.WriteCsvFile ( iKey, oDxfFilNam);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] File name to export to csv file
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     */
     // ----------------------------------------------------------------------------
     int WriteCsvFile(int iKey, std::string oDxfFilNam);
     //==============================================================================
private:  // Private functions
int Dum;        /**< Dummy */
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
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 06.04.16
*/
// ----------------------------------------------------------------------------
class sstDxf02DatabaseCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // dxf database constructor <BR>
  *
  * @param oTmpPrt [in] protocol output file
  */
  // ----------------------------------------------------------------------------
     sstDxf02DatabaseCls(sstMisc01PrtFilCls *oTmpPrt);  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Read all Csv Files into dxf database <BR>
     * iStat = oSstDxfDB.ReadAllCsvFiles(iKey);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] Dxf File Name for new dxf file
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadAllCsvFiles(int iKey, std::string oDxfFilNam);
     //==============================================================================
     /**
     * @brief // get layer table adress from dxf database <BR>
     * oLayTab = oDxfDB.getSstFncLay();
     *
     * @return Layer table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncLayCls* getSstFncLay();
     //==============================================================================
     /**
     * @brief // get block table adress from dxf database <BR>
     * oBlkTab = oDxfDB.getSstFncBlk();
     *
     * @return Block table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncBlkCls* getSstFncBlk();
     //==============================================================================
     /**
     * @brief // get LType table adress from dxf database <BR>
     * oBlkTab = oDxfDB.getSstFncLType();
     *
     * @return LineType table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncLTypeCls* getSstFncLType();
     //==============================================================================
     /**
     * @brief // get arc table adress from dxf database <BR>
     * oArcTab = oDxfDB.getSstFncArc();
     *
     * @return Layer table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncArcCls* getSstFncArc();
     //==============================================================================
     /**
     * @brief // get insert table from dxf database <BR>
     * oInsertTab = oDxfDB.getSstFncInsert();
     *
     * @return insert table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncInsertCls* getSstFncInsert();
     //==============================================================================
     /**
     * @brief // get polyline table from dxf database <BR>
     * oInsertTab = oDxfDB.getSstFncPolyline();
     *
     * @return polyline table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncPolylineCls* getSstFncPolyline();
     //==============================================================================
     /**
     * @brief // get vertex table from dxf database <BR>
     * oVertexTab = oDxfDB.getSstFncVertex();
     *
     * @return vertex table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncVertexCls* getSstFncVertex();
     //==============================================================================
     /**
     * @brief // get hatch table from dxf database <BR>
     * oHatchTab = oDxfDB.getSstFncHatch();
     *
     * @return hatch table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncHatchCls* getSstFncHatch();
     //==============================================================================
     /**
     * @brief // get hatch edge table from dxf database <BR>
     * oHatchEdgeTab = oDxfDB.getSstFncHatchEdge();
     *
     * @return hatch edge table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncHatchEdgeCls* getSstFncHatchEdge();
     //==============================================================================
     /**
     * @brief // get hatch loop table from dxf database <BR>
     * oHatchLoopTab = oDxfDB.getSstFncHatchLoop();
     *
     * @return hatch Loop table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncHatchLoopCls* getSstFncHatchLoop();
     //==============================================================================
     /**
     * @brief // get main table from dxf database <BR>
     * oMainTab = oDxfDB.getSstFncMain();
     *
     * @return Layer table
     */
     // ----------------------------------------------------------------------------
     sstDxf02FncMainCls* getSstFncMain();
     //==============================================================================
     /**
     * @brief // return record number <BR>
     *
     * @return Record number
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getActRecNo() const;
     //==============================================================================
     /**
     * @brief // Set record number <BR>
     *
     * @param value [in] record number
     */
     // ----------------------------------------------------------------------------
     void setActRecNo(const dREC04RECNUMTYP &value);
     //==============================================================================
     /**
     * @brief // return actual entity type <BR>
     *
     * @return actual entity type
     */
     // ----------------------------------------------------------------------------
     RS2::EntityType getActEntType() const;
     //==============================================================================
     /**
     * @brief // Set actual entity type <BR>
     *
     * @param value [in] actual entity type
     */
     // ----------------------------------------------------------------------------
     void setActEntType(const RS2::EntityType &value);
     //==============================================================================

private:  // Private functions
  sstDxf02FncMainCls oSstFncMain;      /**< Main table object */
  sstDxf02FncLayCls oSstFncLay;        /**< layer table object */
  sstDxf02FncBlkCls oSstFncBlk;        /**< Block table object */
  sstDxf02FncLTypeCls oSstFncLType;        /**< LineType table object */
  sstDxf02FncArcCls oSstFncArc;        /**< Arc table object */
  sstDxf02FncInsertCls oSstFncInsert;  /**< Insert table object */
  sstDxf02FncPolylineCls oSstFncPolyline;  /**< polyline table object */
  sstDxf02FncVertexCls oSstFncVertex;  /**< vertex table object */
  sstDxf02FncHatchCls oSstFncHatch;    /**< hatch table object */
  sstDxf02FncHatchEdgeCls oSstFncHatchEdge;  /**< hatch edge table object */
  sstDxf02FncHatchLoopCls oSstFncHatchLoop;  /**< hatch loop table object */
  sstMisc01PrtFilCls *oPrt;                  /**< Protocol object */
  dREC04RECNUMTYP dActRecNo;              // Actual Record Number
  RS2::EntityType eActEntType;            // Actual Entity Type

};
//==============================================================================
/**
* @brief Dxf Import Data Class <BR>
*
* Changed: 09.07.15  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf02ReadCls : public DL_CreationAdapter {
public:
  //==============================================================================
  /**
  * @brief // dxf read object <BR>
  *
  * @param oTmpPrt [in] protocol output file
  */
  // ----------------------------------------------------------------------------
    sstDxf02ReadCls(sstMisc01PrtFilCls *oTmpPrt);
    ~sstDxf02ReadCls();
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addLayer(const DL_LayerData& data);
    //==============================================================================
    /**
    * @brief // Process imported Block data <BR>
    * oSstDxfReadDL.addBlock(data)
    *
    * @param data [in] BlockData
    */
    // ----------------------------------------------------------------------------
    virtual void addBlock(const DL_BlockData& data);
    //==============================================================================
    /**
    * @brief // process end block situation <BR>
    * oSstDxfReadDL.endBlock()
    */
    // ----------------------------------------------------------------------------
    virtual void endBlock();
    //==============================================================================
    /**
    * @brief // Process imported Point data <BR>
    * oSstDxfReadDL.addPoint(data)
    *
    * @param data [in] Point data
    */
    // ----------------------------------------------------------------------------
    virtual void addPoint(const DL_PointData& data);
    //==============================================================================
    /**
    * @brief // Process imported insert data <BR>
    * oSstDxfReadDL.addInsert(data)
    *
    * @param data [in] insert data
    */
    // ----------------------------------------------------------------------------
    virtual void addInsert(const DL_InsertData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addLine(const DL_LineData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addArc(const DL_ArcData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addCircle(const DL_CircleData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addPolyline(const DL_PolylineData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addVertex(const DL_VertexData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void add3dFace(const DL_3dFaceData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addHatch(const DL_HatchData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addHatchEdge(const DL_HatchEdgeData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addHatchLoop(const DL_HatchLoopData& data);
    // virtual void addSolid(const DL_SolidData& data);
    //==============================================================================
    /**
    * @brief // Print Attributes <BR>
    * oSstDxfReadDL.printAttributes()
    */
    // ----------------------------------------------------------------------------
    void printAttributes();
    //==============================================================================
    /**
    * @brief // Set Dxf File Name into object <BR>
    * oSstDxfReadDL.SetDxfFilNam(cDxfFilNam);
    *
    * @param cDxfFilNam [in] Set Dxf File Name
    *
    */
    // ----------------------------------------------------------------------------
    void SetDxfFilNam(char* cDxfFilNam);
    //==============================================================================
private:
    sstDxf02DatabaseCls   oDxfDb; /**< sst dxf database with recmem tech */

    std::string oDxfFilNam;        /**< dxf file name without extension */
    std::string oActBlockNam;      /**< actual block name */
    sstMisc01PrtFilCls *poPrt;     /**< adress of protocol file */
};

//==============================================================================
/**
* @brief dxf write class
*
* Read all csv files, create sst dxf database and export to dxf file <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf02WriteCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Constructor <BR>
  *
  * @param oTmpPrt [in] protocol file object
  */
  // ----------------------------------------------------------------------------
     sstDxf02WriteCls(sstMisc01PrtFilCls *oTmpPrt);  // Constructor
    ~sstDxf02WriteCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Open new dxf file <BR>
     * iStat = oSstDxfWrite.OpenNewDxfFile ( iKey, oDxfFilNam);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] Dxf file name
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int OpenNewDxfFile (int iKey, std::string oDxfFilNam);
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
     //==============================================================================
     /**
     * @brief Set Dxf File name
     *
     * @param oDxfFilNam [in] Dxf File Name
     */
     // ----------------------------------------------------------------------------
     void SetDxfFilNam(std::string oDxfFilNam);
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
     int ReadAllCsvFiles(int iKey);
     //==============================================================================
     /**
     * @brief // Close open object like polyline, if nessasary  <BR>
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteOpenEntities(int iKey);
// ----------------------------------------------------------------------------
private:  // Private functions
  DL_Dxf* dxf;     /**< dxflib dxf */
  DL_WriterA* dw;  /**< dxflib dw */
  sstDxf02DatabaseCls   oDxfDb; /**< sst dxf database with recmem tech */
  std::string oDxfFilNam;      /**< dxf file name without extension */
  sstMisc01PrtFilCls *poPrt;     /**< adress of protocol file */

};
//==============================================================================
/**
* @brief Definition sstDxfBase_Cls
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class sstDxfBase_Cls
{
  public:   // Öffentliche Funktionen
     sstDxfBase_Cls();  // Konstruktor
    // ~sstDxfBase_Cls();  // Destruktor
     //==============================================================================
     /**
     * @brief GetName
     */
     // ----------------------------------------------------------------------------
     void GetName();
     //==============================================================================
     /**
     * @brief SetName
     */
     // ----------------------------------------------------------------------------
     void SetName();
     //==============================================================================
     /**
     * @brief GetID
     *
     * @param ulLocID [out] ulLocID
     */
     // ----------------------------------------------------------------------------
     void GetId( unsigned long *ulLocID);
     //==============================================================================
     /**
     * @brief SetID
     *
     * @param ulLocID [in] ulLocID
     */
     // ----------------------------------------------------------------------------
     void SetId( unsigned long ulLocID);
     //==============================================================================
     /**
     * @brief GetName
     *
     * @param cLocName [out] cLocName
     * @param uiNamLen [out] uiNamLen
     */
     // ----------------------------------------------------------------------------
     void GetName( char *cLocName, unsigned int uiNamLen);
     //==============================================================================
     /**
     * @brief SetName
     *
     * @param cLocName [in] cLocName
     */
     // ----------------------------------------------------------------------------
     void SetName( char *cLocName);
     //==============================================================================
     /**
     * @brief UpdateMinMax
     *
     * @param iKey    [in] For the moment 0
     * @param oVertex [in] oVertex
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdateMinMax (int           iKey,
                       DL_VertexData oVertex);
     //==============================================================================
     /**
     * @brief ResetMinMax
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ResetMinMax (int    iKey);


  private:  // Private Funktionen
  char cName[33];  /**< Name of Dxf Element */
  unsigned long ulID;  /**< Identifier of Dxf Element */
};
//==============================================================================
/**
* @brief Definition sstDxfPolylineCls
*
* dxf polyline with vertex memory
*
* Changed: 07.06.13  Re.
*
* @ingroup sstDxf02Lib
*
* @author Re.
*
* @date 07.06.13
*/
// ----------------------------------------------------------------------------
class sstDxfPolylineCls : public sstDxfBase_Cls
{
  public:   // Öffentliche Funktionen
     // Constructor
  //==============================================================================
  /**
  * @brief Constructor
  *
  * iStat = Blanko ( iKey);
  *
  * More Comment
  *
  * Changed: 16.02.10  Re.
  *
  * @ingroup sst_dxf_lib
  *
  * @author Re.
  *
  * @date 16.02.10
  */
  //------------------------------------------------------------------------------
     sstDxfPolylineCls(): myTestpoly(0,0,0,0)
     {
       // int iStat = 0;
       lActVertex = 0;
       // Heap-Objekt öffnen und Heap anlegen.
       // SST_HPO_Auf_c ( 0, &sVertexHeap, 10, sizeof(DL_VertexData));

       // Initialize Min-Max
       // iStat = Mia_3Ini_c ( 0, &sMiMa);

     }
     // Destructor
     //==============================================================================
     /**
     * @brief Destructor
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     ~sstDxfPolylineCls()
     {
       // int iStat = 0;
       // Heap-Objekt beenden und Heap an BS zurückgeben.
       // SST_HPO_Zu_c ( 0, &sVertexHeap);

     }
     //==============================================================================
     /**
     * @brief AddVertex
     *
     * iStat = Blanko ( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey    [in] For the moment 0
     * @param oVertex [in] vertex record
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int AddVertex(int            iKey,
                   DL_VertexData *oVertex);
     //==============================================================================
     /**
     * @brief Get next Vertex from Object
     *
     * iStat = GetVertex( iKey, *oVertex);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in] For the moment 0
     * @param oVertex: [out] Get next Vertex
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int GetVertex(int            iKey,
                   DL_VertexData *oVertex);
     //==============================================================================
     /**
     * @brief Reset Vertex Getter
     *
     * iStat = Reset( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int ResetGet(int iKey);
     //==============================================================================
     /**
     * @brief Clear all Vertex from Polyline memory
     *
     * iStat = ClearMemory( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int ClearMemory(int iKey);
     //==============================================================================
     /**
     * @brief Clear all Vertex from Polyline memory
     *
     * iStat = ClearMemory( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey       [in] For the moment 0
     * @param lNumVertex [in out] lNumVertex
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int GetNumVertex(int iKey, unsigned long *lNumVertex);
     //==============================================================================
     /**
     * @brief Write PolyLine to Dxf File
     *
     * iStat = WrtPLine2File ( iKey, **dxf, **dw);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey [in] For the moment 0
     * @param dxf  [in out]
     * @param dw   [in out]
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int WrtPLine2File (int           iKey,
                        DL_Dxf      **dxf,
                        DL_WriterA  **dw);

     //==============================================================================
     /**
     * @brief Get actual MinMax from Dxf PolyLine
     *
     * iStat = GetMinMax ( iKey, *sLocMiMa);
     *
     * More Comment
     *
     * Changed: 14.06.13  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in]  For the moment 0
     * @param iKey: [out] MinMax
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 14.06.13
     */
     //------------------------------------------------------------------------------
     // int GetMinMax (int             iKey,
     //               MIMA_3D_Struct *sLocMiMa);
     //==============================================================================

  private:  // Private Funktionen
  DL_PolylineData myTestpoly;    /**< Dxf polyline header */
  std::list <DL_VertexData>  sVertexHeap;      /**< All Vertices in Heap */
  long lActVertex;               /**< vertex number for getvertex */
};
//==============================================================================
/**
* @brief sstdxf_WrtDss2PolyLine
*
* iStat = sstdxf_WrtDss2PolyLine ( iKey, *sPntDss, **dxf, **dw);
*
* More Comment
*
* Changed: 16.02.10  Re.
*
* @ingroup sstDxf02Lib
*
* @param iKey    [in] For the moment 0
* @param sPntDss [in out]
* @param dxf     [in out]
* @param dw      [in out]
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 16.02.10
*/
//------------------------------------------------------------------------------
int sstdxf_WrtDss2PolyLine (int           iKey,
                            sstRec04Cls  *sPntDss,
                            DL_Dxf      **dxf,
                            DL_WriterA  **dw);
//==============================================================================
 
#endif
//
// --------------------------------------------------------------- File End ----
