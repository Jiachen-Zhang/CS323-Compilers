eCC=gcc
splc: clean
	@mkdir bin
	touch bin/splc
	flex lex.l && bison -t -d -y -v syntax.y
	g++ -lfl -ly ast.cpp semantic.cpp ir.cpp y.tab.c -o ./bin/splc
	@chmod +x bin/splc
clean:
	@rm -rf bin/
	@rm -f lex.yy.* y.tab.*
.PHONY: splc