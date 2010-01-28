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

#ifndef __NCTUNS_tbtp_section_h__
#define __NCTUNS_tbtp_section_h__

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "section_draft.h"
#include "tbtp_table.h"

/* Question:
 * 1. in table_to_section, we can cut the middle of frame,
 *	not same with sct
 *
 */

#define MAX_SECTIONS					1000
#define MAX_TBTP_SECTION_SIZE				1024
#define MAX_TBTP_SECTION_SIZE_NO_INCLUDING_CRC32	(MAX_TBTP_SECTION_SIZE - CRC32_SIZE)
#define	TBTP_FRAME_INFO_SIZE				sizeof(Tbtp_frame_info)


/* Note: Since total bytes for storage frame information for one superframe
 * is no larger than 256, the superframe information would not be segmented into
 * multiple sections.
 */
class Tbtp_table_to_section_handler {
  private:
	// These data are stored for section generation.
	Tbtp*				_tbtp_table;
	u_char				_table_id;
	u_int16_t			_network_id;
	u_char				_version_number;
	u_char				_current_next_indicator;
	Tbtp_frame_info_entry*		_ptr_frame_info_entry;

	// _section_length stores the value of 'section_length' filed defined in SI.
	u_int16_t			_section_length[MAX_SECTIONS];
	u_int16_t			_last_section_number;
	u_int16_t			_current_section_number;


  public:
	void				_calculate_last_section_number_and_section_lengths(Tbtp* Tbtp_table);
	void				tbtp_table_to_section_init(Tbtp* Tbtp_table);
	void*				tbtp_table_to_section();

};

/* One Sct_section_to_table_handler instance would correspond to
 * the handling for one Sct table in the section module.
 * The pair (network_id, version_number) identifies
 * distinct Sct table.
 */
class Tbtp_section_to_table_handler {

  private:
	u_int16_t			_network_id;
	u_char				_version_number;
	u_char				_current_next_indicator;
	bool				_received[256];	// The section numbers of sections that have been received.
	u_char				_last_section_number;
	Tbtp*				_ptr_table;
	
	bool				_is_complete();

  public:
  	int 		init(void* section);

	Tbtp*	 	to_table(void* tbtp_section);

	void	set_current_next_indicator(u_char current_next_indicator) 
	{
		_current_next_indicator = current_next_indicator;
	}

	CUR_NEXT_INDICATOR	get_current_next_indicator() 
	{
					return (CUR_NEXT_INDICATOR) _current_next_indicator;
	}

	void	set_version_number(u_char version_number)
	{
		_version_number = version_number;
	}

	u_char get_version_number()
	{
		return _version_number;
	}
};// End of class Sct_section_to_table_handler. 

#endif /* __NCTUNS_tbtp_section_h__ */
