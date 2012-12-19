TARGET=report
TEX=xelatex -shell-escape
BIBTEX=bibtex
READER=mupdf

all: view

rebuild output/$(TARGET).pdf: *.tex output
	cd output && rm -f *.tex && ln -s ../*.tex .
	cd output && $(TEX) $(TARGET).tex 


output: 
	mkdir output
	cd output && rm -f res && ln -s ../res .
	cd output && rm -f pics && ln -s ../pics .

view: output/$(TARGET).pdf

#$(READER) output/$(TARGET).pdf 

clean:
	rm -rf output

run:
	$(READER) output/$(TARGET).pdf 

# compile twice to get cross reference right
final : *.tex  output
	cd output && rm -f *.tex && ln -s ../*.tex  .
	cd output && $(TEX) $(TARGET).tex  && $(TEX) $(TARGET).tex

count:
	@word_count *.tex

dist: output/$(TARGET).pdf
	rm -rf paper
	mkdir paper
	cp output/$(TARGET).pdf paper/
	cp -r screenshots paper/
	7z a -tzip paper.zip paper
	rm -rf paper

.PHONY: all view clean rebuild dist
