# Created by: siasia
# $FreeBSD: head/lang/v8/Makefile 328202 2013-09-24 22:07:10Z vanilla $

PORTNAME=	v8
PORTVERSION=	3.22.8
CATEGORIES=	lang

USE_GITHUB=     yes
NO_STAGE=       yes
GH_ACCOUNT=     v8 
GH_COMMIT=      67efb5d 

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google\'s open source JavaScript engine

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS+= ${LOCALBASE}/bin/gcc47:${PORTSDIR}/lang/gcc47	

USES=		gmake
USE_XZ=		yes
USE_PYTHON=	2.6+
USE_LDCONFIG=	yes
ALL_TARGET=	native
MAKE_ARGS=	library=shared i18nsupport=off werror=no

.include <bsd.port.pre.mk>

MAKE_ENV+=	LINK=g++47
USE_CXX=	g++47
USE_CC=		gcc47

ONLY_FOR_ARCHS=	i386 amd64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${STAGEDIR}/${PREFIX}/bin/d8
	${INSTALL_LIB} -m 755 ${WRKSRC}/out/native/lib.target/libv8.so ${STAGEDIR}/${PREFIX}/lib/libv8.so.1
	${LN} -sf ${PREFIX}/lib/libv8.so.1 ${STAGEDIR}/${PREFIX}/lib/libv8.so
	${INSTALL_DATA} ${WRKSRC}/include/v8.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-debug.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-preparser.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-profiler.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8-testing.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8stdint.h ${STAGEDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/v8config.h ${STAGEDIR}/${PREFIX}/include

.include <bsd.port.post.mk>
