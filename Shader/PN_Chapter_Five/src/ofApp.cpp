#include "ofApp.h"

void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos)
{
	float verts[] = { -w + pos.x, -h + pos.y,  pos.z,
		-w + pos.x,  h + pos.y,  pos.z,
		w + pos.x,  h + pos.y,  pos.z,
		w + pos.x, -h + pos.y,  pos.z };

	float uvs[] = { 0,0, 0,1, 1,1, 1,0 };

	for (int i = 0; i < 4; ++i) {
		int idx = i * 3;
		int uvIdx = i * 2;

		mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
	}

	ofIndexType indices[6] = { 0,1,2,2,3,0 };
	mesh.addIndices(indices, 6);
}

glm::mat4 buildMatrix(glm::vec3 trans, float rot, glm::vec3 scale)
{
	using glm::mat4;
	mat4 translation = glm::translate(trans);
	mat4 rotation = glm::rotate(rot, glm::vec3(0.0, 0.0, 1.0));
	mat4 scaler = glm::scale(scale);
	return translation * rotation * scaler;
}

glm::mat4 buildViewMatrix(CameraData cam) {
	using namespace glm;
	return inverse(buildMatrix(cam.position, cam.rotation, vec3(1, 1, 1)));
}

//--------------------------------------------------------------
void ofApp::setup()
{
	ofDisableArbTex();
	ofEnableDepthTest();

	buildMesh(charMesh, 0.1, 0.2, glm::vec3(0.0, -0.3, 0.0));
	buildMesh(backgroundMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.5));
	buildMesh(sunMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.4));
	buildMesh(cloudMesh, 0.25, 0.15, glm::vec3(0.0, 0.0, 0.0));

	alienImg.load("walk_sheet.png");
	backgroundImg.load("forest.png");
	cloudImg.load("cloud.png");
	sunImg.load("sun.png");

	spritesheetShader.load("spritesheet.vert", "alphaTest.frag");
	opaqueShader.load("cloud.vert", "cloud.frag");
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (walkRight)
	{
		float speed = 0.4 * ofGetLastFrameTime();
		charPos += glm::vec3(speed, 0, 0);
	}

}


//--------------------------------------------------------------
void ofApp::draw() {

	using namespace glm;
	cam.position = vec3(-1, 0, 0);
	mat4 view = buildViewMatrix(cam);

	static float frame = 0.0;
	frame = (frame > 10) ? 0.0 : frame += 0.2;
	glm::vec2 spriteSize = glm::vec2(0.28, 0.19);
	glm::vec2 spriteFrame = glm::vec2((int)frame % 3, (int)frame / 3);

	static float rotation = 0.0f;
	rotation += 0.1f;
	mat4 translationA = translate(vec3(-0.55, 0.0, 0.0));
	mat4 scaleA = scale(vec3(1.5, 1, 1));
	mat4 ourRotation = rotate(rotation, vec3(0.0, 0.0, 1.0));
	mat4 transformA = translationA * scaleA;
	mat4 newMatrix = translationA * ourRotation * inverse(translationA);
	mat4 finalMatrixA = newMatrix * transformA;
	mat4 identity = glm::mat4();

	ofDisableBlendMode();
	ofEnableDepthTest();

	spritesheetShader.begin();
	spritesheetShader.setUniformMatrix4f("view", view);
	spritesheetShader.setUniform2f("size", spriteSize);
	spritesheetShader.setUniform2f("offset", spriteFrame);
	spritesheetShader.setUniformTexture("tex", alienImg, 0);
	spritesheetShader.setUniformMatrix4f("model", glm::translate(charPos));
	charMesh.draw();

	spritesheetShader.end();

	opaqueShader.begin();
	opaqueShader.setUniformMatrix4f("transform", identity);
	opaqueShader.setUniformTexture("tex", backgroundImg, 0);
	backgroundMesh.draw();
	opaqueShader.end();

	ofDisableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);

	mat4 transformB = buildMatrix(vec3(0.4, 0.2, 0.0), 1.0f, vec3(1, 1, 1));

	opaqueShader.begin();
	opaqueShader.setUniformTexture("tex", cloudImg, 0);
	opaqueShader.setUniformMatrix4f("view", view);
	opaqueShader.setUniformMatrix4f("model", finalMatrixA);
	cloudMesh.draw();

	opaqueShader.end();

	//we won't render the sun mesh for this example to give us a better view of the cloud
}

void ofApp::keyPressed(int key)
{
	if (key == ofKey::OF_KEY_RIGHT) {
		walkRight = true;
	}
}

void ofApp::keyReleased(int key)
{
	if (key == ofKey::OF_KEY_RIGHT) {
		walkRight = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
