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
// sstdxf2csv.cpp    09.02.16  Re.    09.02.16  Re.
//
// Tool splits dxf drawing file into object csv files.
// Csv file for layers, blocks, arc elements and so on ...
// Tool uses dxflib as base library.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <list>

#include "dl_dxf.h"
#include "dl_creationadapter.h"

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf02Lib.h>

#include "sstdxf2csv.h"

//=============================================================================
int main(int argc, char** argv)
{
  sstDxf2CsvCls oDxf2Csv;

  // Open Protocol
  int iStat = oDxf2Csv.SST_PrtAuf ( 1, (char*) "Dxf2Csv");
  assert(iStat == 0);

    // Check given arguments:
    if (argc < 2)
    {
        oDxf2Csv.usage();
        return 0;
    }

  oDxf2Csv.testReading(argv[1]);

  // Close Protocol
  iStat = oDxf2Csv.SST_PrtZu ( 1);

  return 0;
}
//=============================================================================
/*
 * @brief Prints error message if file name not specified as command
 * line argument.
 */
void sstDxf2CsvCls::usage() {
    std::cout << "\nUsage: test <DXF file>\n\n";
}
//=============================================================================
void sstDxf2CsvCls::testReading(char* file) {
    // Load DXF file into memory:
    std::cout << "Reading file " << file << "...\n";
    sstDxf01ReadCls* creationClass = new sstDxf01ReadCls();

    creationClass->SetDxfFilNam(file);

    DL_Dxf* dxf = new DL_Dxf();
    if (!dxf->in(file, creationClass)) { // if file open failed
        std::cerr << file << " could not be opened.\n";
        return;
    }
    delete dxf;
    delete creationClass;
}
//=============================================================================
sstDxf2CsvCls::sstDxf2CsvCls()
{

}
//=============================================================================
