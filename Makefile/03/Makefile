EXE = janela

#CXXFLAGS=-lGL -lglfw -lGLEW -DIMGUI_IMPL_OPENGL_LOADER_GLEW

# @ Ignora regras e tudo mais para não aparecer no terminal

CXX = g++
CC = gcc

SOURCES = main.o
SOURCES += imgui/examples/imgui_impl_glfw.o imgui/examples/imgui_impl_opengl3.o
SOURCES += imgui/imgui.o imgui/imgui_demo.o imgui/imgui_draw.o imgui/imgui_widgets.o

CXXFLAGS = -lGLEW -DIMGUI_IMPL_OPENGL_LOADER_GLEW -lglfw

LIBS = -lGL `pkg-config --static --libs glfw3`

CXXFLAGS += -I../ -I../../  `pkg-config --cflags glfw3`
CXXFLAGS += -Wall -Wformat
CFLAGS = $(CXXFLAGS)

ECHO_MESSAGE = Linux

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:imgui/examples/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#%.o:imgui/examples/libs/gl3w/GL/%.c
# %.o:../libs/glad/src/%.c
	#$(CC) $(CFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(SOURCES)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(SOURCES)