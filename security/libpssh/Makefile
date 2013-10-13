# Created by: vagner 
# $FreeBSD: head/security/libpssh/Makefile 328202 2013-10-13 14:47:10Z vagner $

PORTNAME=	libpssh
PORTVERSION=	0.1
CATEGORIES=	security

USE_GITHUB=     yes
NO_STAGE=       yes
GH_ACCOUNT=     vagner 
GH_COMMIT=      4b4267a

MAINTAINER= 	vagner@bsdway.ru	
COMMENT=	Badoo\'s open source asynchronous ssh lib for C/C++

LIB_DEPENDS=	ssh2:${PORTSDIR}/security/libssh2 \
		libevent-2.0.so:${PORTSDIR}/devel/libevent2

USE_GCC=        any
GNU_CONFIGURE=  yes
USE_AUTOTOOLS=  aclocal automake autoconf libtool

.include <bsd.port.pre.mk>

run-autotools:	
	@cd ${WRKSRC} && ${SH} ./autogen.sh

.include <bsd.port.post.mk>
