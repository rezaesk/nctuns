/*
 * Copyright (c) from 2000 to 2009
 * 
 * Network and System Laboratory 
 * Department of Computer Science 
 * College of Computer Science
 * National Chiao Tung University, Taiwan
 * All Rights Reserved.
 * 
 * This source code file is part of the NCTUns 6.0 network simulator.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation is hereby granted (excluding for commercial or
 * for-profit use), provided that both the copyright notice and this
 * permission notice appear in all copies of the software, derivative
 * works, or modified versions, and any portions thereof, and that
 * both notices appear in supporting documentation, and that credit
 * is given to National Chiao Tung University, Taiwan in all publications 
 * reporting on direct or indirect use of this code or its derivatives.
 *
 * National Chiao Tung University, Taiwan makes no representations 
 * about the suitability of this software for any purpose. It is provided 
 * "AS IS" without express or implied warranty.
 *
 * A Web site containing the latest NCTUns 6.0 network simulator software 
 * and its documentations is set up at http://NSL.csie.nctu.edu.tw/nctuns.html.
 *
 * Project Chief-Technology-Officer
 * 
 * Prof. Shie-Yuan Wang <shieyuan@csie.nctu.edu.tw>
 * National Chiao Tung University, Taiwan
 *
 * 09/01/2009
 */

/* convolutional encoder */
unsigned char cvencode(unsigned char* data, int data_start,int bitsize,unsigned char* symbol ,int sym_start, unsigned char state);
int viterbi(unsigned char* symbol, int bitsize, unsigned char* data);
int interleaving(unsigned char* input , unsigned char* output);
int deinterleaving(unsigned char* input , unsigned char* output);
int crc(int crc, unsigned int len, unsigned char* buf);
int firecode(unsigned char* buf,int bitsize, unsigned char *reg);
int CS1_encode(unsigned char* data, unsigned char* symbol);
int CS1_decode(unsigned char* symbol, unsigned char* data);
int CS2_encode(unsigned char* data, unsigned char* symbol);
int CS2_decode(unsigned char* symbol, unsigned char* data);
int CS3_encode(unsigned char* data, unsigned char* symbol);
int CS3_decode(unsigned char* symbol, unsigned char* data);
int CS4_encode(unsigned char* data, unsigned char* symbol);
int CS4_decode(unsigned char* symbol, unsigned char* data);
