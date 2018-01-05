/*
 * =====================================================================================
 *
 *       Filename:  hole_file.c
 *
 *    Description:  how to make file with holes
 *
 *        Version:  1.0
 *        Created:  2018年01月04日 10时37分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


dd if=/dev/urandom bs=4096 count=2 of=fwh//create fwh file ,size=8k
$ll fwh
-rw-rw-r-- 1 wanghui wanghui 8192  1月  4 10:40 fwh
$ls -s fwh
8 fwh
$du -s fwh
8	fwh


dd if=/dev/urandom seek=7 bs=4096 count=2 of=fwh
$ll fwh
-rw-rw-r-- 1 wanghui wanghui    36864  1月  4 10:43 fwh
$ls -s fwh
16 fwh
$du -s fwh
16	fwh

dd if=/dev/urandom  bs=4096 count=9 of=fwnh
$ll fwnh
-rw-rw-r-- 1 wanghui wanghui    36864  1月  4 10:23 fwnh
$ls -s fwnh
36 fwnh
$du -s fwnh
36	fwnh
