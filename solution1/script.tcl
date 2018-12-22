############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project convoluter
set_top convolute
add_files convoluter/convoluter.cpp
add_files -tb convoluter/convoluter_test.cpp
add_files -tb ../../../Users/chris/Projects/zynq_afgangsprojekt/python/mnist_example.csv
open_solution "solution1"
set_part {xczu3eg-sbva484-1-e} -tool vivado
create_clock -period 10 -name default
#source "./convoluter/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
