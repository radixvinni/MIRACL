cmake_minimum_required(VERSION 2.8)
project(Miracl)
include_directories (include/)
include_directories (.)
set (SCHOOF
  source/curve/schoof.cpp
  source/curve/poly.cpp
  source/curve/polymod.cpp
  source/ecn.cpp
  source/crt.cpp
  source/zzn.cpp
  source/big.cpp
)
set (SCHOOF2
  source/curve/schoof2.cpp
  source/curve/poly2.cpp
  source/curve/poly2mod.cpp
  source/crt.cpp
  source/big.cpp
  source/gf2m.cpp
  source/ec2.cpp
)
set (SEA
  source/curve/sea.cpp
  source/curve/poly.cpp
  source/curve/polymod.cpp
  source/curve/polyxy.cpp
  source/ecn.cpp
  source/crt.cpp
  source/zzn.cpp
  source/big.cpp
)
set (MODPOL
  source/curve/modpol.cpp
  source/curve/ps_zzn.cpp
  source/zzn.cpp
  source/big.cpp
)
set (MIRACL
	source/mr87f.c
	source/mr87v.c
	source/mraes.c
	source/mralloc.c
	source/mrarth0.c
	source/mrarth1.c
	source/mrarth2.c
	source/mrarth3.c
	source/mrbits.c
	source/mrbrick.c
	source/mrbuild.c
	source/mrcore.c
	source/mrcrt.c
	source/mrcurve.c
	source/mrdouble.c
	source/mrebrick.c
	source/mrec2m.c
	source/mrecn2.c
	source/mrfast.c
	source/mrflash.c
	source/mrflsh1.c
	source/mrflsh2.c
	source/mrflsh3.c
	source/mrflsh4.c
	source/mrfrnd.c
	source/mrgcd.c
	source/mrgcm.c
	source/mrgf2m.c
	source/mrio1.c
	source/mrio2.c
	source/mrjack.c
	source/mrlucas.c
	source/mrmonty.c
	source/mrmuldv.c
	source/mrpi.c
	source/mrpower.c
	source/mrprime.c
	source/mrrand.c
	source/mrround.c
	source/mrscrt.c
	source/mrshs.c
	source/mrshs256.c
	source/mrshs512.c
	source/mrsmall.c
	source/mrsroot.c
	source/mrstrong.c
	source/mrxgcd.c
	source/mrzzn2.c
	source/mrzzn2b.c
	source/mrzzn3.c
)
configure_file(source/mrmuldv.ccc source/mrmuldv.c)
if (MSVC)
	configure_file(include/mirdef.ccc include/mirdef.h)
  add_definitions (/W0)
elseif (CMAKE_COMPILER_IS_GNUCXX)
 	configure_file(include/mirdef.lnx include/mirdef.h)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  add_definitions (-w -fPIC)
else()
  add_definitions (-w)
endif()
endif (MSVC)
add_library (Miracl ${MIRACL})


add_library (sea SHARED ${SEA})
target_link_libraries(sea Miracl)

add_library (modpol SHARED ${MODPOL})
target_link_libraries(modpol Miracl)

add_library (schoof SHARED ${SCHOOF})
target_link_libraries(schoof Miracl)

add_library (schoof2 SHARED ${SCHOOF2})
target_link_libraries(schoof2 Miracl)

add_executable (test.exe test/test.cpp)
target_link_libraries(test.exe dl)

# install (FILES ${HEADERS} DESTINATION include)
install (TARGETS Miracl sea modpol schoof schoof2 DESTINATION lib)
