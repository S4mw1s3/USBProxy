/*
 * Copyright 2013 Dominic Spill
 * Copyright 2013 Adam Stasiak
 *
 * This file is part of USB-MitM.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 *
 * USBDeviceProxyNull.h
 *
 * Created on: Nov 15, 2013
 */
#ifndef USBDEVICEPROXYNULL_H_
#define USBDEVICEPROXYNULL_H_

#include "USBDeviceProxy.h"

class USBDeviceProxy_Null: public USBDeviceProxy {
private:
	bool connected=false;
public:
	USBDeviceProxy_Null() {}
	virtual ~USBDeviceProxy_Null();

	virtual int connect() {connected=true;return 0;}
	virtual void disconnect() {connected=false;}
	virtual void reset() {}
	virtual bool is_connected() {return connected;}

	//this should be done synchronously
	virtual int control_request(const usb_ctrlrequest *setup_packet, int *nbytes, __u8* dataptr) {return 0;}
	virtual void send_data(__u8 endpoint,__u8 attributes,__u16 maxPacketSize,__u8* dataptr,int length) {}
	virtual void receive_data(__u8 endpoint,__u8 attributes,__u16 maxPacketSize,__u8** dataptr, int* length) {*length=0;}

	virtual __u8 get_address() {return 0;}
	virtual const char* toString() {return (char*)"Null Device";}

};

#endif /* USBDEVICEPROXYNULL_H_ */
