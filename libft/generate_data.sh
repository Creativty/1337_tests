#/bin/sh
# **************************************************************************** #
SOURCE_FILES=""
SOURCE_COUNT=0

for f in ../../libft/*.c; do
	BASE_NAME=$(basename ${f})
	SOURCE_FILES+="$base_name "
	SOURCE_COUNT=$(expr $SOURCE_COUNT + 1)
done

TEST_LIST=""
TEST_COUNT=0
for f in ./funcs/*.c;
do
	FILENAME=$(basename ${f} .c)
	TEST="${FILENAME}_test"
	TEST_LIST="$TEST_LIST $TEST"
	TEST_COUNT=$(expr $TEST_COUNT + 1)
done
# **************************************************************************** #
FILE="""
#ifndef DATA_H\n
#define DATA_H\n
\n
"""

for FUNC in $TEST_LIST;
do
	FILE+="int\t$FUNC(void);\n"
done

FILE+="""
static const char\t*testNames[$SOURCE_COUNT] = {\n
"""

for SOURCE in $SOURCES_LIBFT;
do
	TEST_NAME=$(basename ${SOURCE} .c)
	FILE+="\t\"$TEST_NAME\",\n"
done

FILE+="""
};\n
static const int\ttestCount = $SOURCE_COUNT;\n

static int (*const testFuncs[])(void) = {\n
"""

for FUNC in $TEST_LIST;
do
	FILE+="\t$FUNC,\n"
done
FILE+="""
};\n

typedef enum {\n
"""
# **************************************************************************** #
PREFIX="ft_"
for FUNC in $TEST_LIST;
do
	# NAME=$(echo ${$FUNC#"$PREFIX"} | tr '[:lower:]' '[:upper:]')
	_NAME=${FUNC#"$PREFIX"}
	NAME=$(echo ${_NAME%"_test"} | tr '[:lower:]' '[:upper:]')
	FILE+="""\tTEST_GROUP_$NAME,\n"""
done


FILE+="""
\tTEST_GROUP_NIL,\n
}\tTestGroup;\n
#endif
"""
# **************************************************************************** #
echo $FILE
