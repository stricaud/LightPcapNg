// light_types.h
// Created on: Jul 23, 2016

// Copyright (c) 2016 Radu Velea

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef INCLUDE_LIGHT_TYPES_H_
#define INCLUDE_LIGHT_TYPES_H_

typedef enum {
	LIGHT_FALSE = 0,
	LIGHT_TRUE = 1,
//	LIGHT_MAYBE = 2,
} light_boolean;

typedef enum {
	LIGHT_INFO_TYPE = 0,
	LIGHT_INFO_LENGTH = 1,
	LIGHT_INFO_BODY = 2,
	LIGHT_INFO_OPTIONS = 3,
	LIGHT_INFO_MAX = 4,
} light_info;

typedef enum {
		/** BSD loopback encapsulation */
		LIGHT_LINKTYPE_NULL = 0,
		/** IEEE 802.3 Ethernet */
		LIGHT_LINKTYPE_ETHERNET = 1,
		/** AX.25 packet */
		LIGHT_LINKTYPE_AX25 = 3,
		/** IEEE 802.5 Token Ring */
		LIGHT_LINKTYPE_IEEE802_5 = 6,
		/** ARCNET Data Packets */
		LIGHT_LINKTYPE_ARCNET_BSD = 7,
		/** SLIP, encapsulated with a LIGHT_LINKTYPE_SLIP header */
		LIGHT_LINKTYPE_SLIP = 8,
		/** PPP, as per RFC 1661 and RFC 1662 */
		LIGHT_LINKTYPE_PPP = 9,
		/** FDDI, as specified by ANSI INCITS 239-1994 */
		LIGHT_LINKTYPE_FDDI = 10,
		/** Raw IP */
		LIGHT_LINKTYPE_DLT_RAW1 = 12,
		/** Raw IP (OpenBSD) */
		LIGHT_LINKTYPE_DLT_RAW2 = 14,
		/** PPP in HDLC-like framing, as per RFC 1662, or Cisco PPP with HDLC framing, as per section 4.3.1 of RFC 1547 */
		LIGHT_LINKTYPE_PPP_HDLC = 50,
		/** PPPoE */
		LIGHT_LINKTYPE_PPP_ETHER = 51,
		/** RFC 1483 LLC/SNAP-encapsulated ATM */
		LIGHT_LINKTYPE_ATM_RFC1483 = 100,
		/** Raw IP */
		LIGHT_LINKTYPE_RAW = 101,
		/** Cisco PPP with HDLC framing */
		LIGHT_LINKTYPE_C_HDLC = 104,
		/** IEEE 802.11 wireless LAN */
		LIGHT_LINKTYPE_IEEE802_11 = 105,
		/** Frame Relay */
		LIGHT_LINKTYPE_FRELAY = 107,
		/** OpenBSD loopback encapsulation */
		LIGHT_LINKTYPE_LOOP = 108,
		/** Linux "cooked" capture encapsulation */
		LIGHT_LINKTYPE_LINUX_SLL = 113,
		/** Apple LocalTalk */
		LIGHT_LINKTYPE_LTALK = 114,
		/** OpenBSD pflog */
		LIGHT_LINKTYPE_PFLOG = 117,
		/** Prism monitor mode information followed by an 802.11 header */
		LIGHT_LINKTYPE_IEEE802_11_PRISM = 119,
		/** RFC 2625 IP-over-Fibre Channel */
		LIGHT_LINKTYPE_IP_OVER_FC = 122,
		/** ATM traffic, encapsulated as per the scheme used by SunATM devices */
		LIGHT_LINKTYPE_SUNATM = 123,
		/** Radiotap link-layer information followed by an 802.11 header */
		LIGHT_LINKTYPE_IEEE802_11_RADIOTAP = 127,
		/** ARCNET Data Packets, as described by the ARCNET Trade Association standard ATA 878.1-1999 */
		LIGHT_LINKTYPE_ARCNET_LINUX = 129,
		/** Apple IP-over-IEEE 1394 cooked header */
		LIGHT_LINKTYPE_APPLE_IP_OVER_IEEE1394 = 138,
		/** Signaling System 7 Message Transfer Part Level 2 */
		LIGHT_LINKTYPE_MTP2_WITH_PHDR = 139,
		/** Signaling System 7 Message Transfer Part Level 2 */
		LIGHT_LINKTYPE_MTP2 = 140,
		/** Signaling System 7 Message Transfer Part Level 3 */
		LIGHT_LINKTYPE_MTP3 = 141,
		/** Signaling System 7 Signalling Connection Control Part */
		LIGHT_LINKTYPE_SCCP = 142,
		/** Signaling System 7 Signalling Connection Control Part */
		LIGHT_LINKTYPE_DOCSIS = 143,
		/** Linux-IrDA packets */
		LIGHT_LINKTYPE_LINUX_IRDA = 144,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER0 = 147,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER1 = 148,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER2 = 149,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER3 = 150,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER4 = 151,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER5 = 152,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER6 = 153,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER7 = 154,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER8 = 155,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER9 = 156,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER10 = 157,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER11 = 158,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER12 = 159,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER13 = 160,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER14 = 161,
		/** Reserved for private use */
		LIGHT_LINKTYPE_USER15 = 162,
		/** AVS monitor mode information followed by an 802.11 header */
		LIGHT_LINKTYPE_IEEE802_11_AVS = 163,
		/** BACnet MS/TP frames */
		LIGHT_LINKTYPE_BACNET_MS_TP = 165,
		/** PPP in HDLC-like encapsulation, like LIGHT_LINKTYPE_PPP_HDLC, but with the 0xff address byte replaced by a direction indication - 0x00 for incoming and 0x01 for outgoing */
		LIGHT_LINKTYPE_PPP_PPPD = 166,
		/** General Packet Radio Service Logical Link Control */
		LIGHT_LINKTYPE_GPRS_LLC = 169,
		/** Transparent-mapped generic framing procedure */
		LIGHT_LINKTYPE_GPF_T = 170,
		/** Frame-mapped generic framing procedure */
		LIGHT_LINKTYPE_GPF_F = 171,
		/** Link Access Procedures on the D Channel (LAPD) frames */
		LIGHT_LINKTYPE_LINUX_LAPD = 177,
		/** Bluetooth HCI UART transport layer */
		LIGHT_LINKTYPE_BLUETOOTH_HCI_H4 = 187,
		/** USB packets, beginning with a Linux USB header */
		LIGHT_LINKTYPE_USB_LINUX = 189,
		/** Per-Packet Information information */
		LIGHT_LINKTYPE_PPI = 192,
		/** IEEE 802.15.4 wireless Personal Area Network */
		LIGHT_LINKTYPE_IEEE802_15_4 = 195,
		/** Various link-layer types, with a pseudo-header, for SITA */
		LIGHT_LINKTYPE_SITA = 196,
		/** Various link-layer types, with a pseudo-header, for Endace DAG cards; encapsulates Endace ERF record */
		LIGHT_LINKTYPE_ERF = 197,
		/** Bluetooth HCI UART transport layer */
		LIGHT_LINKTYPE_BLUETOOTH_HCI_H4_WITH_PHDR = 201,
		/** AX.25 packet, with a 1-byte KISS header containing a type indicator */
		LIGHT_LINKTYPE_AX25_KISS = 202,
		/** Link Access Procedures on the D Channel (LAPD) frames */
		LIGHT_LINKTYPE_LAPD = 203,
		/** PPP, as per RFC 1661 and RFC 1662, preceded with a one-byte pseudo-header with a zero value meaning "received by this host" and a non-zero value meaning  "sent by this host" */
		LIGHT_LINKTYPE_PPP_WITH_DIR = 204,
		/** Cisco PPP with HDLC framing */
		LIGHT_LINKTYPE_C_HDLC_WITH_DIR = 205,
		/** Frame Relay */
		LIGHT_LINKTYPE_FRELAY_WITH_DIR = 206,
		/** IPMB over an I2C circuit */
		LIGHT_LINKTYPE_IPMB_LINUX = 209,
		/** IEEE 802.15.4 wireless Personal Area Network */
		LIGHT_LINKTYPE_IEEE802_15_4_NONASK_PHY = 215,
		/** USB packets, beginning with a Linux USB header */
		LIGHT_LINKTYPE_USB_LINUX_MMAPPED = 220,
		/** Fibre Channel FC-2 frames, beginning with a Frame_Header */
		LIGHT_LINKTYPE_FC_2 = 224,
		/** Fibre Channel FC-2 frames */
		LIGHT_LINKTYPE_FC_2_WITH_FRAME_DELIMS = 225,
		/** Solaris ipnet pseudo-header */
		LIGHT_LINKTYPE_IPNET = 226,
		/** CAN (Controller Area Network) frames, with a pseudo-header as supplied by Linux SocketCAN */
		LIGHT_LINKTYPE_CAN_SOCKETCAN = 227,
		/** Raw IPv4; the packet begins with an IPv4 header */
		LIGHT_LINKTYPE_IPV4 = 228,
		/** Raw IPv6; the packet begins with an IPv6 header */
		LIGHT_LINKTYPE_IPV6 = 229,
		/** IEEE 802.15.4 wireless Personal Area Network, without the FCS at the end of the frame */
		LIGHT_LINKTYPE_IEEE802_15_4_NOFCS = 230,
		/** Raw D-Bus messages, starting with the endianness flag, followed by the message type, etc., but without the authentication handshake before the message sequence */
		LIGHT_LINKTYPE_DBUS = 231,
		/** DVB-CI (DVB Common Interface for communication between a PC Card module and a DVB receiver), with the message format specified by the PCAP format for DVB-CI specification */
		LIGHT_LINKTYPE_DVB_CI = 235,
		/** Variant of 3GPP TS 27.010 multiplexing protocol (similar to, but not the same as, 27.010) */
		LIGHT_LINKTYPE_MUX27010 = 236,
		/** D_PDUs as described by NATO standard STANAG 5066, starting with the synchronization sequence, and including both header and data CRCs */
		LIGHT_LINKTYPE_STANAG_5066_D_PDU = 237,
		/** Linux netlink NETLINK NFLOG socket log messages */
		LIGHT_LINKTYPE_NFLOG = 239,
		/** Pseudo-header for Hilscher Gesellschaft für Systemautomation mbH netANALYZER devices, followed by an Ethernet frame, beginning with the MAC header and ending with the FCS */
		LIGHT_LINKTYPE_NETANALYZER = 240,
		/** Pseudo-header for Hilscher Gesellschaft für Systemautomation mbH netANALYZER devices, followed by an Ethernet frame, beginning with the preamble, SFD, and MAC header, and ending with the FCS */
		LIGHT_LINKTYPE_NETANALYZER_TRANSPARENT = 241,
		/** IP-over-InfiniBand, as specified by RFC 4391 section 6 */
		LIGHT_LINKTYPE_IPOIB = 242,
		/** MPEG-2 Transport Stream transport packets, as specified by ISO 13818-1/ITU-T Recommendation H.222.0 */
		LIGHT_LINKTYPE_MPEG_2_TS = 243,
		/** Pseudo-header for ng4T GmbH's UMTS Iub/Iur-over-ATM and Iub/Iur-over-IP format as used by their ng40 protocol tester */
		LIGHT_LINKTYPE_NG40 = 244,
		/** Pseudo-header for NFC LLCP packet captures, followed by frame data for the LLCP Protocol as specified by NFCForum-TS-LLCP_1.1 */
		LIGHT_LINKTYPE_NFC_LLCP = 245,
		/** Raw InfiniBand frames, starting with the Local Routing Header */
		LIGHT_LINKTYPE_INFINIBAND = 247,
		/** SCTP packets, as defined by RFC 4960, with no lower-level protocols such as IPv4 or IPv6 */
		LIGHT_LINKTYPE_SCTP = 248,
		/** USB packets, beginning with a USBPcap header */
		LIGHT_LINKTYPE_USBPCAP = 249,
		/** Serial-line packet header for the Schweitzer Engineering Laboratories "RTAC" product */
		LIGHT_LINKTYPE_RTAC_SERIAL = 250,
		/** Bluetooth Low Energy air interface Link Layer packets */
		LIGHT_LINKTYPE_BLUETOOTH_LE_LL = 251,
		/** Linux Netlink capture encapsulation */
		LIGHT_LINKTYPE_NETLINK = 253,
		/** Bluetooth Linux Monitor encapsulation of traffic for the BlueZ stack */
		LIGHT_LINKTYPE_BLUETOOTH_LINUX_MONITOR = 254,
		/** Bluetooth Basic Rate and Enhanced Data Rate baseband packets */
		LIGHT_LINKTYPE_BLUETOOTH_BREDR_BB = 255,
		/** Bluetooth Low Energy link-layer packets */
		LIGHT_LINKTYPE_BLUETOOTH_LE_LL_WITH_PHDR = 256,
		/** PROFIBUS data link layer packets, as specified by IEC standard 61158-6-3 */
		LIGHT_LINKTYPE_PROFIBUS_DL = 257,
		/** Apple PKTAP capture encapsulation */
		LIGHT_LINKTYPE_PKTAP = 258,
		/** Ethernet-over-passive-optical-network packets */
		LIGHT_LINKTYPE_EPON = 259,
		/** IPMI trace packets, as specified by Table 3-20 "Trace Data Block Format" in the PICMG HPM.2 specification */
		LIGHT_LINKTYPE_IPMI_HPM_2 = 260,
		/** Per Joshua Wright <jwright@hasborg.com>, formats for Z-Wave RF profiles R1 and R2 captures */
		LIGHT_LINKTYPE_ZWAVE_R1_R2 = 261,
		/** Per Joshua Wright <jwright@hasborg.com>, formats for Z-Wave RF profile R3 captures */
		LIGHT_LINKTYPE_ZWAVE_R3 = 262,
		/** Formats for WattStopper Digital Lighting Management (DLM) and Legrand Nitoo Open protocol common packet structure captures */
		LIGHT_LINKTYPE_WATTSTOPPER_DLM = 263,
		/** Messages between ISO 14443 contactless smartcards (Proximity Integrated Circuit Card, PICC) and card readers (Proximity Coupling Device, PCD), with the message format specified by the PCAP format for ISO14443 specification */
		LIGHT_LINKTYPE_ISO_14443 = 264
} light_link_layer_type;

#endif /* INCLUDE_LIGHT_TYPES_H_ */
