# Created by:
# $FreeBSD$

PORTNAME=	libevdev
PORTVERSION=	1.3.2
CATEGORIES=	comms
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Linux Event Device library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake libtool pkgconfig python tar:xz
USE_AUTOTOOLS=	aclocal automake autoconf

BASE_HEADERS=	input.h uinput.h

post-patch:
	${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} -n 10 ${REINPLACE_CMD} \
	    -e 's|linux/types.h|sys/types.h|g; \
		s|_IOC_READ|IOC_OUT|g; \
		s|_IOC_WRITE|IOC_IN|g; \
		s|__u8|uint8_t|g; s|__s8|int8_t|g; \
		s|__u16|uint16_t|g; s|__s16|int16_t|g; \
		s|__u32|uint32_t|g; s|__s32|int32_t|g; \
		s|__u64|uint64_t|g; s|__s64|int64_t|g'

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/linux
.for i in ${BASE_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/linux/${i} \
		${STAGEDIR}${PREFIX}/include/linux/
.endfor

.include <bsd.port.mk>

