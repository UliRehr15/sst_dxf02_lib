# sst_dxf02_lib

sst_dxf02_lib stores dxf data in sst tables (sst_rec04_lib).
for every dxf entity type like ARC, MTEXT and so on there is a table.
this sst dxf tables could by stored in csv, so editing with spreedsheets
like excel is possible.


fork from sst_dxf01_lib: change license

change license to GNU General Public License version 2 because of use of LibreCAD.

Based on dxflib, extends dxflib
Uses functions from LibreCAD2

Compile with QT 5.5 and QTCreator 3.5

Structure of coding projects should be:

.. [libs]  <BR>
   [dxflib] from github <BR>
   [muParser]  <BR>
   [sstLibreCAD2Lib]  <BR>
   [sst_str01_lib]  <BR>
   [sst_misc01_lib]  <BR>
   [sst_rec04_lib]  <BR>
   [sst_dxf02_lib]  <BR>

28.02.16: Version 1.0: sst dxf lib: Tool Dxf2Csv: Realized: Layer Csv Table, Block Csv table, ARC Element Csv  <BR>
05.03.16: Version 1.1: Dxf2Csv: Arc Csv links to Layer Csv.  <BR>
05.03.16: Version 1.2: Dxf2Csv: Supports now INSERT element.  <BR>
10.03.16: Version 1.3: Csv2Dxf: Tool frame and new table MAIN.  <BR>
29.04.16: Version 1.4: Tools Dxf2Csv and Csv2Dxf: Full support of ARC and INSERT.  <BR>
30.05.16: Version 1.5: Tool Dxf2Csv: Support of HATCH and POLYLINE.  <BR>
13.06.16: Version 1.6: Tool Csv2Dxf: Support of POLYLINE, extend support of attributes.  <BR>
17.06.16: Version 1.7: Tool Csv2Dxf: Support of HATCH.  <BR>
22.06.16: Version 1.8: General handling of layer/block data in entities.  <BR>
29.06.16: Version 1.9: Support for POLYLINE/HATCH in Block data.  <BR>
05.07.16: Version 1.10: Problems with color and width fixed.  <BR>
13.07.16: Version 1.11: new testframe for general testing.  <BR>
27.09.16: Version 1.12: Preparing works for entities circle, mtext, text. <BR>
21.10.16: Version 1.13: App Dxf2Csv: Full Support for circle, mtext, text. <BR>
28.10.16: Version 1.14: App Csv2Dxf: Full Support for circle, mtext, text. <BR>
                        Rise precision of decimal places to 4 for writing double values to csv <BR>
                        Caused by problems drawing filled circles in librecad. <BR>
