# Ports collection makefile for: isdn4bsd-kmod
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	isdn4bsd-kmod
PORTVERSION=	2.0.1
DISTNAME=	isdn4bsd-${PORTVERSION}
CATEGORIES=	comms kld
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ISDN4BSD kernel module driver for various ISDN and analog phone adapters

USE_BZIP2=	yes

LICENSE=	BSD
KMODDIR=	/boot/modules
KMODNAME=	i4b
BINDIR=		${PREFIX}/sbin
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
MAKE_JOBS_SAFE= yes

LIB_DEPENDS=    capi20.1:${PORTSDIR}/comms/libcapi

PLIST_SUB=	KMODNAME="${KMODNAME}" \
		KMODDIR="${KMODDIR}" \
		BINDIR="${BINDIR}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"

OPTIONS= \
		DEBUG "Build with debugging support" Off \
		HFC "Build HFC-XXX driver" On \
		ING "Build ING driver" Off \
		IPR "Build IPR driver" Off \
		IPR_VJ "Build IPR driver with VJ support" Off \
		LOOP "Build loopback test driver" Off \
		MAN "Intall manual pages" On \
		RBCH "Build RBCH driver" Off \
		SPPP "Build SPPP driver" Off \
		TEL "Build TEL driver" Off \
		TRACE "Build TRACE driver" On \
		YEALINK "Build YEALINK driver" On

.include <bsd.port.pre.mk>

MAKE_ARGS+=" HAVE_KMOD=YES"

.if defined(WITH_DEBUG)
PLIST_SUB+= HAVE_DEBUG=YES
.endif
.if defined(WITH_HFC)
PLIST_SUB+= HAVE_ISDN_HFC_DRIVER=YES
.endif
.if defined(WITH_ING)
PLIST_SUB+= HAVE_ING_DRIVER=YES
.endif
.if defined(WITH_IPR)
PLIST_SUB+= HAVE_IPR_DRIVER=YES
.endif
.if defined(WITH_IPR_VJ)
PLIST_SUB+= HAVE_IPR_VJ=YES
.endif
.if defined(WITH_LOOP)
PLIST_SUB+= HAVE_ISDN_LOOP_DRIVER=YES
.endif
.if defined(WITH_RBCH)
PLIST_SUB+= HAVE_RBCH_DRIVER=YES
.endif
.if defined(WITH_SPPP)
PLIST_SUB+= HAVE_SPPP_DRIVER=YES
.endif
.if defined(WITH_TEL)
PLIST_SUB+= HAVE_TEL_DRIVER=YES
.endif
.if defined(WITH_TRACE)
PLIST_SUB+= HAVE_TRACE_DRIVER=YES
.endif
.if defined(WITH_YEALINK)
PLIST_SUB+= HAVE_YEALINK_DRIVER=YES
.endif
.if defined(WITH_MAN)
PLIST_SUB+= HAVE_MAN=YES
.else
PLIST_SUB+= HAVE_NO_MAN=YES
.endif

do-configure:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile \
		${PLIST_SUB} configure

do-install:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile install
	kldxref ${KMODDIR}

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>
