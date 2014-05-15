# Ports collection makefile for: isdn4bsd-kmod
# Date created: Feb 29 2012
# Whom:
#
# $FreeBSD$
#

PORTNAME=	isdn4bsd-kmod
PORTVERSION=	2.0.10
CATEGORIES=	comms kld
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/
DISTNAME=	isdn4bsd-${PORTVERSION}

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	ISDN4BSD kernel module driver for various ISDN and analog phone adapters

LICENSE=	BSD

LIB_DEPENDS=	libcapi20.1:${PORTSDIR}/comms/libcapi

SSP_UNSAFE=	kernel module does not support ssp
USES=		tar:bzip2
KMODDIR=	${STAGEDIR}/boot/modules
KMODNAME=	i4b
BINDIR=		${STAGEDIR}${PREFIX}/sbin
LIBDIR=		${STAGEDIR}${PREFIX}/lib
INCLUDEDIR=	${STAGEDIR}${PREFIX}/include
MANDIR=		${STAGEDIR}${PREFIX}/man/man
MAKE_JOBS_SAFE=	yes

I4B_CONFIG=	KMODNAME="${KMODNAME}" \
		KMODDIR="${KMODDIR}" \
		BINDIR="${BINDIR}" \
		LIBDIR="${LIBDIR}" \
		INCLUDEDIR="${INCLUDEDIR}" \
		MANDIR="${MANDIR}"
PLIST_SUB=	KMODDIR="${KMODDIR}" \
		KMODNAME="${KMODNAME}"

OPTIONS_DEFINE= DEBUG HFC ING IPR IPR_VJ LOOP MAN \
    RBCH SPPP TEL TRACE YEALINK

OPTIONS_DEFAULT= HFC MAN TEL TRACE YEALINK

DEBUG_DESC=Build with debugging support
HFC_DESC=Build HFC-XXX driver
ING_DESC=Build ING driver
IPR_DESC=Build IPR driver
IPR_VJ_DESC=Build IPR driver with VJ support
LOOP_DESC=Build loopback test driver
MAN_DESC=Intall manual pages
RBCH_DESC=Build RBCH driver
SPPP_DESC=Build SPPP driver
TEL_DESC=Build TEL driver
TRACE_DESC=Build TRACE driver
YEALINK_DESC=Build YEALINK driver

.include <bsd.port.options.mk>

MAKE_ARGS+=	HAVE_KMOD=YES

.if ${PORT_OPTIONS:MDEBUG}
I4B_CONFIG+=	HAVE_DEBUG=YES
.endif
.if ${PORT_OPTIONS:MHFC}
I4B_CONFIG+=	HAVE_ISDN_HFC_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MING}
I4B_CONFIG+=	HAVE_ING_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MIPR}
I4B_CONFIG+=	HAVE_IPR_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MIPR_VJ}
I4B_CONFIG+=	HAVE_IPR_VJ=YES
.endif
.if ${PORT_OPTIONS:MLOOP}
I4B_CONFIG+=	HAVE_ISDN_LOOP_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MRBCH}
I4B_CONFIG+=	HAVE_RBCH_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MSPPP}
I4B_CONFIG+=	HAVE_SPPP_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MTEL}
I4B_CONFIG+=	HAVE_TEL_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MTRACE}
I4B_CONFIG+=	HAVE_TRACE_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MYEALINK}
I4B_CONFIG+=	HAVE_YEALINK_DRIVER=YES
.endif
.if ${PORT_OPTIONS:MMAN}
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
