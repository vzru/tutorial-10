void InitializeScene()
{
	std::string animationPath = "../../assets/animations/";
	std::string modelsPath = "../../assets/models/";

	mesh = std::make_shared<TTK::OBJMesh>();
	mesh->loadMesh(modelsPath + "guy.obj");

	skinnedGameObject.name = "root";
	skinnedGameObject.initializeSkeletonFromHTR(animationPath + "jab.HTR", animationPath + "guy_weights.xml", mesh);

	glEnable(GL_TEXTURE_2D);
	
	// If you want to put a texture on the character, create a Texture2D object named "meshTexture" and uncomment below
	// You also need to call Texture2D::bind prior to drawing the mesh
	//meshTexture.loadTextureFromFile("../../assets/textures/guy.png");
}