#include "GLLoader.h"

Duno::Graphics::RenderEngine::GLLoader::GLLoader()
{
	vaoLength = 0;
}

Duno::Graphics::RenderEngine::GLLoader::~GLLoader()
{
	cleanUp();
}

Duno::Graphics::RenderEngine::Types::PlainModel
Duno::Graphics::RenderEngine::GLLoader::load(float* data, unsigned int* indices)
{
	//create new VAO
	int VAO = createVAO();

	if (!indices == NULL) {
		bindIndicesBuffer(indices);
	}

	if (data != NULL) {
		storeDataInVBO(3, data);
	}

	unbindVAO();

	return Types::PlainModel(0,0,0,false); //have it blank for now
}


int Duno::Graphics::RenderEngine::GLLoader::createVAO()
{
	GLuint vaoID;

	//Generate new vao
	glGenVertexArrays(1,&vaoID);

	//add VAO to the list
	vaos.push_back(vaoID);	

	//bind the vao
	glBindVertexArray(vaoID);	

	return vaoID;
}

void Duno::Graphics::RenderEngine::GLLoader::unbindVAO()
{
	glBindVertexArray(0);
}


GLuint Duno::Graphics::RenderEngine::GLLoader::storeDataInVBO(int dataSize, float* data)
{
	//create new gl int variable
	GLuint vboID;


	//assign it to a new buffer
	glGenBuffers(1, &vboID);

	//add vboID to vbos list
	vbos.push_back(vboID);

	//bind the vbo
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glVertexAttribPointer(vaoLength, dataSize, GL_FLOAT, false, 0, data);

	//increase the number of vbos in the vao
	vaoLength++;

	//unbind the vbo
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return vboID;

}


void Duno::Graphics::RenderEngine::GLLoader::bindIndicesBuffer(unsigned int* indices)
{

	GLuint vboID;

	glGenBuffers(GL_ELEMENT_ARRAY_BUFFER,&vboID);

	vbos.push_back(vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices)/sizeof(indices[0]), indices, GL_STATIC_DRAW);


}

void Duno::Graphics::RenderEngine::GLLoader::cleanUp()
{
	for (GLuint vbo : vbos) {
		glDeleteBuffers(1,&vbo);																//delete vbos
	}

	for (GLuint vao : vaos) {
		glDeleteVertexArrays(1,&vao);															//delete vaos
	}
}
