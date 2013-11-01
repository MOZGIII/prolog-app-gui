# Set swipl binary
isEmpty(SWIPL_BINARY) {
	SWIPL_BINARY="swipl"
}

# Load options from swipl
isEmpty(PLDUMP) {
	PLDUMP = $$system(\"$$SWIPL_BINARY\" --dump-runtime-variables)
}

# Set SWI-Prolog options
isEmpty(PLBASE) { PLBASE = $$system( 'echo \'$$PLDUMP\' | grep -o -P "(?<=PLBASE=\\\").+?(?=\\\")"' ) }
isEmpty(PLARCH) { PLARCH = $$system( 'echo \'$$PLDUMP\' | grep -o -P "(?<=PLARCH=\\\").+?(?=\\\")"' ) }
isEmpty(PLLIB)  { PLLIB  = $$system( 'echo \'$$PLDUMP\' | grep -o -P "(?<=PLLIB=\\\").+?(?=\\\")"' ) }
isEmpty(PLLIBS) { PLLIBS = $$system( 'echo \'$$PLDUMP\' | grep -o -P "(?<=PLLIBS=\\\").+?(?=\\\")"' ) }

# Include SWI-Prolog
INCLUDEPATH += "$$PLBASE/include"
LIBS        += "-L'$$quote('$$PLBASE/lib/$$PLARCH')'"
LIBS        += "-L'$$quote('$$PLBASE/lib')'"
LIBS        += $$PLLIBS $$PLLIB
