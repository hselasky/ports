# $FreeBSD: head/x11-drivers/xf86-input-mouse/Makefile 374982 2014-12-19 23:03:54Z dumbbell $

PORTNAME=	xf86-input-evdev
PORTVERSION=	2.9.1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org event device input driver

LIB_DEPENDS=	libevdev.so:${PORTSDIR}/comms/libevdev

XORG_CAT=	driver

GNU_CONFIGURE=yes

USES=		autoreconf gmake libtool pathfix pkgconfig gettext

post-patch:
	${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} -n 10 ${REINPLACE_CMD} \
	    -e 's|linux/types.h|sys/types.h|g; \
	    	s|linux/version.h|sys/param.h|g; \
		s|_IOC_READ|IOC_OUT|g; \
		s|_IOC_WRITE|IOC_IN|g; \
		s|__u8|uint8_t|g; s|__s8|int8_t|g; \
		s|__u16|uint16_t|g; s|__s16|int16_t|g; \
		s|__u32|uint32_t|g; s|__s32|int32_t|g; \
		s|__u64|uint64_t|g; s|__s64|int64_t|g'

.include <bsd.port.mk>
