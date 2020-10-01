#! /bin/bash

echo "-----------------------------------------------------"
echo "Script to create ts-files for translations"
echo "-----------------------------------------------------"


DIR_CURRENT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
DIR_BINARY="${1}"
DIR_L10N="${DIR_CURRENT}/l10n"
INSPECT_DIR="${DIR_CURRENT} $(realpath ${DIR_CURRENT}/../../libraries/businesslogic)"
INSPECT_FILES=$(find ${INSPECT_DIR} -type f -regex ".*/.*\.\(h\|cpp\|qml\)$")


echo "DIR_CURRENT                 ${DIR_CURRENT}"
echo "DIR_BINARY                  ${DIR_BINARY}"
echo "DIR_L10N                    ${DIR_L10N}"
echo "DIR_INSPECT                 ${INSPECT_DIR}"
echo "FILES                       ${INSPECT_FILES}"


/opt/Qt/5.15.0/gcc_64/bin/lupdate \
    ${INSPECT_FILES} \
    -recursive \
    -no-obsolete \
    -locations none \
    -ts "${DIR_L10N}/german_de.ts"


/opt/Qt/5.15.0/gcc_64/bin/lrelease \
    "${DIR_L10N}/german_de.ts" \
    -compress

cp -v "${DIR_L10N}/"*.qm "${DIR_BINARY}"
