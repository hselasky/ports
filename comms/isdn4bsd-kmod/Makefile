# Ports collection makefile for: isdn4bsd-kmod
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	isdn4bsd-kmod
PORTVERSION=	2.0.7
CATEGORIES=	comms kld
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/
DISTNAME=	isdn4bsd-${PORTVERSION}

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ISDN4BSD kernel module driver for various ISDN and analog phone adapters

LICENSE=	BSD

LIB_DEPENDS=	capi20.1:${PORTSDIR}/comms/libcapi

USE_BZIP2=	yes
KMODDIR=	/boot/modules
KMODNAME=	i4b
BINDIR=		${PREFIX}/sbin
LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
MANDIR=		${PREFIX}/man/man
MAKE_JOBS_SAFE=	yes

I4B_CONFIG=	KMODNAME="${KMODNAME}" \
		KMODDIR="${KMODDIR}" \
		BINDIR="${BINDIR}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"
PLIST_SUB=	KMODDIR="${KMODDIR}" \
		KMODNAME="${KMODNAME}"

OPTIONS=	DEBUG "Build with debugging support" Off \
		HFC "Build HFC-XXX driver" On \
		ING "Build ING driver" Off \
		IPR "Build IPR driver" Off \
		IPR_VJ "Build IPR driver with VJ support" Off \
		LOOP "Build loopback test driver" Off \
		MAN "Intall manual pages" On \
		RBCH "Build RBCH driver" Off \
		SPPP "Build SPPP driver" Off \
		TEL "Build TEL driver" On \
		TRACE "Build TRACE driver" On \
		YEALINK "Build YEALINK driver" On

.include <bsd.port.options.mk>

MAKE_ARGS+=	HAVE_KMOD=YES

.if defined(WITH_DEBUG)
I4B_CONFIG+=	HAVE_DEBUG=YES
.endif
.if defined(WITH_HFC)
I4B_CONFIG+=	HAVE_ISDN_HFC_DRIVER=YES
.endif
.if defined(WITH_ING)
I4B_CONFIG+=	HAVE_ING_DRIVER=YES
.endif
.if defined(WITH_IPR)
I4B_CONFIG+=	HAVE_IPR_DRIVER=YES
.endif
.if defined(WITH_IPR_VJ)
I4B_CONFIG+=	HAVE_IPR_VJ=YES
.endif
.if defined(WITH_LOOP)
I4B_CONFIG+=	HAVE_ISDN_LOOP_DRIVER=YES
.endif
.if defined(WITH_RBCH)
I4B_CONFIG+=	HAVE_RBCH_DRIVER=YES
.endif
.if defined(WITH_SPPP)
I4B_CONFIG+=	HAVE_SPPP_DRIVER=YES
.endif
.if defined(WITH_TEL)
I4B_CONFIG+=	HAVE_TEL_DRIVER=YES
.endif
.if defined(WITH_TRACE)
I4B_CONFIG+=	HAVE_TRACE_DRIVER=YES
.endif
.if defined(WITH_YEALINK)
I4B_CONFIG+=	HAVE_YEALINK_DRIVER=YES
.endif
.if defined(WITH_MAN)
I4B_CONFIG+=	HAVE_MAN=YES
NO_MANCOMPRESS=	yes
MAN4=	i4b.4.gz i4bcapi.4.gz i4bctl.4.gz i4bdss1.4.gz i4bing.4.gz i4bipr.4.gz \
	i4bisppp.4.gz i4brbch.4.gz i4btel.4.gz i4btrc.4.gz ihfc.4.gz
.else
I4B_CONFIG+=	HAVE_NO_MAN=YES
.endif

do-configure:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile \
		${I4B_CONFIG} configure

do-install:
	${MAKE} ${MAKE_ARGS} -C ${WRKSRC} -f ${WRKSRC}/Makefile install
	@/usr/sbin/kldxref ${KMODDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>
