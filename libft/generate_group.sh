OUT_FILE="#include \"../shared.h\"\n\nTestGroup\ttest_match_group(char *name)\n{\n"

TEST_NAMES=()
TEST_GROUPS=()
TEST_COUNT=0
TEST_GROUP_PREFIX="FT_"
for f in ./funcs/*.c;
do
	TEST_NAME=$(basename ${f} .c)
	# TEST_NAMES="$TEST_NAMES ${TEST_NAME}_test"
	TEST_NAMES+=("${TEST_NAME}")


	TEST_GROUP=$(echo $TEST_NAME | tr '[:lower:]' '[:upper:]' | sed 's/FT_//')
	# TEST_GROUPS="$TEST_GROUPS TEST_GROUP_${TEST_GROUP%"$TEST_GROUP_PREFIX"}"
	TEST_GROUPS+=("TEST_GROUP_${TEST_GROUP%"$TEST_GROUP_PREFIX"}")

	TEST_COUNT=$(expr $TEST_COUNT + 1)
done

#* ************************************************************************** *#

for _i in $(seq $TEST_COUNT);
do
	i=$(expr $_i - 1)
	LINE="\tif (strcmp(name, \"${TEST_NAMES[$i]}\") == 0) return ${TEST_GROUPS[$i]};"
	OUT_FILE+="$LINE\n"
done

OUT_FILE+="""
\treturn (TEST_GROUP_NIL);\n
}\n
"""

echo $OUT_FILE
