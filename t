[1mdiff --git a/Arcanoid.vcxproj b/Arcanoid.vcxproj[m
[1mindex 5f34853..af38d06 100644[m
[1m--- a/Arcanoid.vcxproj[m
[1m+++ b/Arcanoid.vcxproj[m
[36m@@ -237,9 +237,11 @@[m [mC:\Users\Coherent\Libraries\OpenFrameworks\of_upstream\addons\ofxEntityX\src;%(A[m
     <ClCompile Include="..\..\..\addons\ofxBox2d\src\ofxBox2dPolygon.cpp" />[m
     <ClCompile Include="..\..\..\addons\ofxBox2d\src\ofxBox2dRect.cpp" />[m
     <ClCompile Include="..\..\..\addons\ofxEntityX\src\ofxEntityX.cpp" />[m
[32m+[m[32m    <ClCompile Include="src\SoundSystem.cpp" />[m
     <ClCompile Include="src\BallSystem.cpp" />[m
     <ClCompile Include="src\CollisionSystem.cpp" />[m
     <ClCompile Include="src\CommandQueueComponent.cpp" />[m
[32m+[m[32m    <ClCompile Include="src\GameSounds.cpp" />[m
     <ClCompile Include="src\GameTextures.cpp" />[m
     <ClCompile Include="src\InputSystem.cpp" />[m
     <ClCompile Include="src\Keyboard.cpp" />[m
[36m@@ -251,6 +253,7 @@[m [mC:\Users\Coherent\Libraries\OpenFrameworks\of_upstream\addons\ofxEntityX\src;%(A[m
     <ClCompile Include="src\SelectComponent.cpp" />[m
     <ClCompile Include="src\SelectSystem.cpp" />[m
     <ClCompile Include="src\ShootComponent.cpp" />[m
[32m+[m[32m    <ClCompile Include="src\SoundPlayer.cpp" />[m
     <ClCompile Include="src\SpriteRenderer.cpp" />[m
     <ClCompile Include="src\StickComponent.cpp" />[m
     <ClCompile Include="src\PaddleSystem.cpp" />[m
[36m@@ -335,10 +338,13 @@[m [mC:\Users\Coherent\Libraries\OpenFrameworks\of_upstream\addons\ofxEntityX\src;%(A[m
     <ClInclude Include="..\..\..\addons\ofxBox2d\src\ofxBox2dRender.h" />[m
     <ClInclude Include="..\..\..\addons\ofxBox2d\src\ofxBox2dUtils.h" />[m
     <ClInclude Include="..\..\..\addons\ofxEntityX\src\ofxEntityX.h" />[m
[32m+[m[32m    <ClInclude Include="src\SoundSystem.h" />[m
[32m+[m[32m    <ClInclude Include="src\SoundType.h" />[m
     <ClInclude Include="src\BallSystem.h" />[m
     <ClInclude Include="src\CollisionEvent.h" />[m
     <ClInclude Include="src\CollisionHandler.h" />[m
     <ClInclude Include="src\CommandQueueComponent.h" />[m
[32m+[m[32m    <ClInclude Include="src\GameSounds.h" />[m
     <ClInclude Include="src\MenuEvents.h" />[m
     <ClInclude Include="src\EventHandler.h" />[m
     <ClInclude Include="src\PowerEvents.h" />[m
[36m@@ -357,6 +363,8 @@[m [mC:\Users\Coherent\Libraries\OpenFrameworks\of_upstream\addons\ofxEntityX\src;%(A[m
     <ClInclude Include="src\PhysicsSystem.h" />[m
     <ClInclude Include="src\Renderer.h" />[m
     <ClInclude Include="src\ShootComponent.h" />[m
[32m+[m[32m    <ClInclude Include="src\SoundPlayer.h" />[m
[32m+[m[32m    <ClInclude Include="src\Sounds.h" />[m
     <ClInclude Include="src\SpriteRenderer.h" />[m
     <ClInclude Include="src\StickComponent.h" />[m
     <ClInclude Include="src\KeyboardInputComponent.h" />[m
[1mdiff --git a/Arcanoid.vcxproj.filters b/Arcanoid.vcxproj.filters[m
[1mindex 2b77139..1ff9f97 100644[m
[1m--- a/Arcanoid.vcxproj.filters[m
[1m+++ b/Arcanoid.vcxproj.filters[m
[36m@@ -265,6 +265,15 @@[m
     <ClCompile Include="src\StickComponent.cpp">[m
       <Filter>src\Game\Power\Stick</Filter>[m
     </ClCompile>[m
[32m+[m[32m    <ClCompile Include="src\GameSounds.cpp">[m
[32m+[m[32m      <Filter>src\Sound</Filter>[m
[32m+[m[32m    </ClCompile>[m
[32m+[m[32m    <ClCompile Include="src\SoundPlayer.cpp">[m
[32m+[m[32m      <Filter>src\Sound</Filter>[m
[32m+[m[32m    </ClCompile>[m
[32m+[m[32m    <ClCompile Include="src\SoundSystem.cpp">[m
[32m+[m[32m      <Filter>src\Game\Audio</Filter>[m
[32m+[m[32m    </ClCompile>[m
   </ItemGroup>[m
   <ItemGroup>[m
     <Filter Include="src">[m
[36m@@ -357,6 +366,12 @@[m
     <Filter Include="src\Game\Power\Stick">[m
       <UniqueIdentifier>{ebcd9931-d470-4d7d-8ccc-dbc9a06f7983}</UniqueIdentifier>[m
     </Filter>[m
[32m+[m[32m    <Filter Include="src\Game\Audio">[m
[32m+[m[32m      <UniqueIdentifier>{4e50f82c-b494-4dd8-b4a8-2842aaba857c}</UniqueIdentifier>[m
[32m+[m[32m    </Filter>[m
[32m+[m[32m    <Filter Include="src\Sound">[m
[32m+[m[32m      <UniqueIdentifier>{4cdf633b-97c0-417e-b623-67ab7cccacb4}</UniqueIdentifier>[m
[32m+[m[32m    </Filter>[m
   </ItemGroup>[m
   <ItemGroup>[m
     <ClInclude Include="src\ofApp.h">[m
[36m@@ -683,6 +698,21 @@[m
     <ClInclude Include="src\CollisionEvent.h">[m
       <Filter>src\Game\Collision</Filter>[m
     </ClInclude>[m
[32m+[m[32m    <ClInclude Include="src\GameSounds.h">[m
[32m+[m[32m      <Filter>src\Sound</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="src\SoundPlayer.h">[m
[32m+[m[32m      <Filter>src\Sound</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="src\Sounds.h">[m
[32m+[m[32m      <Filter>src\Sound</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="src\SoundSystem.h">[m
[32m+[m[32m      <Filter>src\Game\Audio</Filter>[m
[32m+[m[32m    </ClInclude>[m
[32m+[m[32m    <ClInclude Include="src\SoundType.h">[m
[32m+[m[32m      <Filter>src\Game\Audio</Filter>[m
[32m+[m[32m    </ClInclude>[m
   </ItemGroup>[m
   <ItemGroup>[m
     <ResourceCompile Include="icon.rc" />[m
[1mdiff --git a/src/CollisionEvent.h b/src/CollisionEvent.h[m
[1mindex d8d0e87..a0b51a0 100644[m
[1m--- a/src/CollisionEvent.h[m
[1m+++ b/src/CollisionEvent.h[m
[36m@@ -4,6 +4,6 @@[m
 [m
 struct CollisionEvent[m
 {[m
[31m-	Entity collides;[m
[31m-	Entity with;[m
[32m+[m	[32mEntity a;[m
[32m+[m	[32mEntity b;[m
 };[m
\ No newline at end of file[m
[1mdiff --git a/src/CollisionSystem.cpp b/src/CollisionSystem.cpp[m
[1mindex 250d70b..4161710 100644[m
[1m--- a/src/CollisionSystem.cpp[m
[1m+++ b/src/CollisionSystem.cpp[m
[36m@@ -1,10 +1,20 @@[m
 #include "CollisionSystem.h"[m
[32m+[m[32m#include "CollisionEvent.h"[m
 [m
[31m-CollisionSystem::CollisionSystem(ofxBox2d * box2d)[m
[32m+[m[32mCollisionSystem::CollisionSystem(ofxBox2d * box2d, EventManager * events)[m
 	:[m
[31m-	m_box2d(box2d)[m
[32m+[m	[32mm_box2d(box2d),[m
[32m+[m	[32mm_events(events)[m
 {[m
 	assert(box2d); // we need an instance![m
[32m+[m
[32m+[m	[32mm_box2d->enableEvents();[m
[32m+[m	[32mofAddListener(m_box2d->contactEndEvents, this, &CollisionSystem::onCollision);[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mCollisionSystem::~CollisionSystem()[m
[32m+[m[32m{[m
[32m+[m	[32mofRemoveListener(m_box2d->contactEndEvents, this, &CollisionSystem::onCollision);[m
 }[m
 [m
 void CollisionSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)[m
[36m@@ -12,3 +22,15 @@[m [mvoid CollisionSystem::update(EntityManager & entities, EventManager & events, Ti[m
 	// update internal box2d collision and physics[m
 	m_box2d->update();[m
 }[m
[32m+[m
[32m+[m[32mvoid CollisionSystem::onCollision(ofxBox2dContactArgs & args)[m
[32m+[m[32m{[m
[32m+[m	[32m// assumes PhysicsComponent has set the entity id in the user data[m
[32m+[m	[32massert(args.a->GetUserData() != nullptr);[m
[32m+[m	[32massert(args.b->GetUserData() != nullptr);[m
[32m+[m
[32m+[m	[32mEntity a = *(Entity*)args.a->GetUserData();[m
[32m+[m	[32mEntity b = *(Entity*)args.b->GetUserData();[m
[32m+[m
[32m+[m	[32mm_events->emit<CollisionEvent>({ a, b });[m
[32m+[m[32m}[m
[1mdiff --git a/src/CollisionSystem.h b/src/CollisionSystem.h[m
[1mindex e178351..d789ab0 100644[m
[1m--- a/src/CollisionSystem.h[m
[1m+++ b/src/CollisionSystem.h[m
[36m@@ -6,9 +6,13 @@[m
 class CollisionSystem : public System<CollisionSystem>[m
 {[m
 public:[m
[31m-	CollisionSystem(ofxBox2d * box2d = nullptr);[m
[32m+[m	[32mCollisionSystem(ofxBox2d * box2d, EventManager * events);[m
[32m+[m	[32m~CollisionSystem();[m
 [m
 	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;[m
[32m+[m[41m	[m
[32m+[m	[32mvoid onCollision(ofxBox2dContactArgs & args);[m
 [m
 	ofxBox2d * m_box2d;[m
[32m+[m	[32mEventManager * m_events;[m
 };[m
\ No newline at end of file[m
[1mdiff --git a/src/GameTextures.cpp b/src/GameTextures.cpp[m
[1mindex 79ac786..6eed21b 100644[m
[1m--- a/src/GameTextures.cpp[m
[1m+++ b/src/GameTextures.cpp[m
[36m@@ -2,32 +2,32 @@[m
 [m
 GameTextures::GameTextures()[m
 {[m
[31m-	notFound.allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);[m
[32m+[m	[32mm_notFound.allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);[m
 [m
[31m-	textures[NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);[m
[31m-	textures[BASIC_0].load("basicTile.png");[m
[31m-	textures[STRONG_0].load("strongTile_0.png");[m
[31m-	textures[STRONG_1].load("strongTile_1.png");[m
[32m+[m	[32mm_textures[TextureId::NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);[m
[32m+[m	[32mm_textures[TextureId::BASIC_0].load("basicTile.png");[m
[32m+[m	[32mm_textures[TextureId::STRONG_0].load("strongTile_0.png");[m
[32m+[m	[32mm_textures[TextureId::STRONG_1].load("strongTile_1.png");[m
 	[m
[31m-	textures[PADDLE].load("paddle.png");[m
[31m-	textures[BALL].load("ball.png");[m
[31m-[m
[31m-	textures[LEVEL_0].load("level_background.png");[m
[31m-[m
[31m-	textures[NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);[m
[31m-	textures[PLAY].load("play.png");[m
[31m-	textures[PLAY_SEL].load("play_sel.png");[m
[31m-	textures[CREDITS].load("credits.png");[m
[31m-	textures[CREDITS_SEL].load("credits_sel.png");[m
[31m-	textures[EXIT].load("exit.png");[m
[31m-	textures[EXIT_SEL].load("exit_sel.png");[m
[32m+[m	[32mm_textures[TextureId::PADDLE].load("paddle.png");[m
[32m+[m	[32mm_textures[TextureId::BALL].load("ball.png");[m
[32m+[m[41m			   [m
[32m+[m	[32mm_textures[TextureId::LEVEL_0].load("level_background.png");[m
[32m+[m[41m	[m
[32m+[m	[32mm_textures[TextureId::NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);[m
[32m+[m	[32mm_textures[TextureId::PLAY].load("play.png");[m
[32m+[m	[32mm_textures[TextureId::PLAY_SEL].load("play_sel.png");[m
[32m+[m	[32mm_textures[TextureId::CREDITS].load("credits.png");[m
[32m+[m	[32mm_textures[TextureId::CREDITS_SEL].load("credits_sel.png");[m
[32m+[m	[32mm_textures[TextureId::EXIT].load("exit.png");[m
[32m+[m	[32mm_textures[TextureId::EXIT_SEL].load("exit_sel.png");[m
 }[m
 [m
 const ofTexture & GameTextures::getTexture(TextureId texture)[m
 {[m
[31m-	if(textures.find(texture) != textures.end())[m
[32m+[m	[32mif(m_textures.find(texture) != m_textures.end())[m
 	{[m
[31m-		return textures.at(texture).getTexture();[m
[32m+[m		[32mreturn m_textures.at(texture).getTexture();[m
 	}[m
[31m-	return notFound.getTexture();[m
[32m+[m	[32mreturn m_notFound.getTexture();[m
 }[m
\ No newline at end of file[m
[1mdiff --git a/src/GameTextures.h b/src/GameTextures.h[m
[1mindex 0e75878..21e11fd 100644[m
[1m--- a/src/GameTextures.h[m
[1m+++ b/src/GameTextures.h[m
[36m@@ -12,6 +12,6 @@[m [mpublic:[m
 	const ofTexture & getTexture(TextureId texture);[m
 [m
 private:[m
[31m-	std::map<TextureId, ofImage> textures;[m
[31m-	ofImage notFound;[m
[32m+[m	[32mstd::map<TextureId, ofImage> m_textures;[m
[32m+[m	[32mofImage m_notFound;[m
 };[m
\ No newline at end of file[m
[1mdiff --git a/src/Level.cpp b/src/Level.cpp[m
[1mindex d6a4bf2..53a0d3b 100644[m
[1m--- a/src/Level.cpp[m
[1m+++ b/src/Level.cpp[m
[36m@@ -19,6 +19,7 @@[m
 #include "InputSystem.h"[m
 #include "PowerSystem.h"[m
 #include "PhysicsSystem.h"[m
[32m+[m[32m#include "SoundSystem.h"[m
 [m
 #include "StickComponent.h"[m
 [m
[36m@@ -28,11 +29,14 @@[m
 [m
 #define PHYSICS_SCALE 1024[m
 [m
[31m-Level::Level(const Params & params, const Visuals & visuals, std::function<void()> onLevelEnd)[m
[32m+[m[32mtypedef TypeComponent<TileType> TileTypeComponent;[m
[32m+[m
[32m+[m[32mLevel::Level(const Params & params, const Visuals & visuals, std::function<void()> onLevelEnd, SoundPlayer * soundPlayer)[m
 	:[m
 	m_params(params),[m
 	m_visuals(visuals),[m
[31m-	m_levelEndHandler(onLevelEnd)[m
[32m+[m	[32mm_levelEndHandler(onLevelEnd),[m
[32m+[m	[32mm_soundPlayer(soundPlayer)[m
 {[m
 	setupBox2d();[m
 	setupEntityX();[m
[36m@@ -73,11 +77,12 @@[m [mvoid Level::setupEntityX()[m
 {[m
 	systems.add<InputSystem>();[m
 	systems.add<TileSystem>(m_visuals.tileMap, m_params.tiles->count());[m
[31m-	systems.add<CollisionSystem>(&m_box2d);[m
[32m+[m	[32msystems.add<CollisionSystem>(&m_box2d, &events);[m
 	systems.add<PaddleSystem>();[m
 	systems.add<BallSystem>();[m
 	systems.add<PowerSystem>();[m
 	systems.add<PhysicsSystem>();[m
[32m+[m	[32msystems.add<SoundSystem>(m_soundPlayer);[m
 	systems.configure();[m
 [m
 	this->events.subscribe<LevelEndEvent>(m_levelEndHandler);[m
[36m@@ -90,11 +95,11 @@[m [mvoid Level::createTiles()[m
 						m_visuals.tileMatrixRegion.height / m_params.tiles->nRows);[m
 [m
 	int index = -1;[m
[31m-	for (TileMatrix::TileType tiletype : m_params.tiles->matrix)[m
[32m+[m	[32mfor (TileType tiletype : m_params.tiles->matrix)[m
 	{[m
 		index++;[m
 [m
[31m-		if (tiletype == TileMatrix::EMPTY)[m
[32m+[m		[32mif (tiletype == TileType::NONE)[m
 		{[m
 			continue;[m
 		}[m
[36m@@ -115,23 +120,24 @@[m [mvoid Level::createTiles()[m
 			CollisionInfo(false, b2BodyType::b2_staticBody),[m
 			m_box2d.getWorld()[m
 		);[m
[32m+[m		[32mentity.assign<SoundSystem::SoundTypeComponent>(SoundType::TILE);[m
 [m
 		switch (tiletype)[m
 		{[m
[31m-		case TileMatrix::EMPTY:[m
[32m+[m		[32mcase TileType::NONE:[m
 			continue;[m
 			break;[m
[31m-		case TileMatrix::BASIC:[m
[32m+[m		[32mcase TileType::BASIC:[m
 		{[m
 			entity.assign<SpriteComponent>(TextureId::BASIC_0);[m
[31m-			entity.assign<TypeComponent<TileType>>(TileType::BASIC);[m
[32m+[m			[32mentity.assign<TileTypeComponent>(TileType::BASIC);[m
 			entity.assign<HitsComponent>(1);[m
 			break;[m
 		}[m
[31m-		case TileMatrix::STRONG:[m
[32m+[m		[32mcase TileType::STRONG:[m
 		{[m
 			entity.assign<SpriteComponent>(TextureId::STRONG_1);[m
[31m-			entity.assign<TypeComponent<TileType>>(TileType::STRONG);[m
[32m+[m			[32mentity.assign<TileTypeComponent>(TileType::STRONG);[m
 			entity.assign<HitsComponent>(2);[m
 			break;[m
 		}[m
[36m@@ -162,6 +168,7 @@[m [mvoid Level::createPaddle()[m
 	m_paddle.assign<KeyboardInputComponent>('a', 'd', 0, 0, ' ');[m
 	m_paddle.assign<CommandQueueComponent>();[m
 	m_paddle.assign<PaddleControllerComponent>(params);[m
[32m+[m	[32mm_paddle.assign<SoundSystem::SoundTypeComponent>(SoundType::PADDLE);[m
 }[m
 [m
 void Level::createBall()[m
[36m@@ -182,6 +189,7 @@[m [mvoid Level::createBall()[m
 		m_box2d.getWorld()[m
 	);[m
 	m_ball.assign<SpriteComponent>(TextureId::BALL);[m
[32m+[m	[32mm_ball.assign<SoundSystem::SoundTypeComponent>(SoundType::BALL);[m
 }[m
 [m
 void Level::createBounds()[m
[36m@@ -196,6 +204,7 @@[m [mvoid Level::createBounds()[m
 		CollisionInfo(false, b2BodyType::b2_staticBody),[m
 		m_box2d.getWorld()[m
 	);[m
[32m+[m	[32mleftBound.assign<SoundSystem::SoundTypeComponent>(SoundType::BOUND);[m
 [m
 	auto rightBound = entities.create();[m
 	rightBound.assign<PhysicsComponent>[m
[36m@@ -205,6 +214,8 @@[m [mvoid Level::createBounds()[m
 		CollisionInfo(false, b2BodyType::b2_staticBody),[m
 		m_box2d.getWorld()[m
 	);[m
[32m+[m	[32mrightBound.assign<SoundSystem::SoundTypeComponent>(SoundType::BOUND);[m
[32m+[m
 	auto topBound = entities.create();[m
 	topBound.assign<PhysicsComponent>[m
 	([m
[36m@@ -213,6 +224,7 @@[m [mvoid Level::createBounds()[m
 		CollisionInfo(false, b2BodyType::b2_staticBody),[m
 		m_box2d.getWorld()[m
 	);[m
[32m+[m	[32mtopBound.assign<SoundSystem::SoundTypeComponent>(SoundType::BOUND);[m
 }[m
 [m
 [m
[36m@@ -236,11 +248,15 @@[m [mvoid Level::draw(Renderer * renderer)[m
 		renderer->drawSpriteCentered(position.position / PHYSICS_SCALE, position.size / PHYSICS_SCALE, visual.texture);[m
 	});[m
 [m
[31m-	//entities.each<PhysicsComponent, PositionComponent, SpriteComponent>([m
[31m-	//	[renderer](Entity entity, PhysicsComponent & physics, PositionComponent & position, SpriteComponent & visual)[m
[31m-	//{[m
[31m-	//	physics.collision->draw();[m
[31m-	//});[m
[32m+[m	[32mofPushStyle();[m
[32m+[m	[32mofNoFill();[m
[32m+[m	[32mofSetLineWidth(2.0f);[m
[32m+[m	[32mentities.each<PhysicsComponent, PositionComponent, SpriteComponent>([m
[32m+[m		[32m[renderer](Entity entity, PhysicsComponent & physics, PositionComponent & position, SpriteComponent & visual)[m
[32m+[m	[32m{[m
[32m+[m		[32mphysics.collision->draw();[m
[32m+[m	[32m});[m
[32m+[m	[32mofPopStyle();[m
 }[m
 [m
 void Level::input(char input)[m
[1mdiff --git a/src/Level.h b/src/Level.h[m
[1mindex 3499087..fce78c6 100644[m
[1m--- a/src/Level.h[m
[1m+++ b/src/Level.h[m
[36m@@ -8,6 +8,7 @@[m
 #include "TileType.h"[m
 #include "StickPower.h"[m
 #include "ofxBox2d.h"[m
[32m+[m[32m#include "SoundPlayer.h"[m
 [m
 class TileMatrix;[m
 [m
[36m@@ -47,7 +48,7 @@[m [mpublic:[m
 		//UseShootEventHandler m_shootHandler;[m
 	};[m
 [m
[31m-	Level(const Params & params, const Visuals & visuals, std::function<void()> onLevelEnd);[m
[32m+[m	[32mLevel(const Params & params, const Visuals & visuals, std::function<void()> onLevelEnd, SoundPlayer * soundPlayer);[m
 	~Level();[m
 [m
 	void update(double delta);[m
[36m@@ -65,7 +66,7 @@[m [mpublic:[m
 	LevelEndHandler m_levelEndHandler;[m
 [m
 	ofxBox2d m_box2d;[m
[31m-[m
[32m+[m	[32mSoundPlayer * m_soundPlayer;[m
 	PowerEvents m_powerEvents;[m
 [m
 	void onLevelStart();[m
[1mdiff --git a/src/LevelManager.cpp b/src/LevelManager.cpp[m
[1mindex b663478..ae66e0b 100644[m
[1m--- a/src/LevelManager.cpp[m
[1m+++ b/src/LevelManager.cpp[m
[36m@@ -1,11 +1,12 @@[m
 #include "LevelManager.h"[m
 [m
[31m-LevelManager::LevelManager(const std::vector<Level::Params> & levels, Level::Visuals visuals, std::function<void()> onGameEnd)[m
[32m+[m[32mLevelManager::LevelManager(const std::vector<Level::Params> & levels, Level::Visuals visuals, std::function<void()> onGameEnd, SoundPlayer * soundPlayer)[m
 	:[m
 	m_visuals(visuals),[m
 	c_onGameEnd(onGameEnd),[m
 	m_levels(levels),[m
[31m-	m_currentLevelIt(m_levels.begin())[m
[32m+[m	[32mm_currentLevelIt(m_levels.begin()),[m
[32m+[m	[32mm_soundPlayer(soundPlayer)[m
 {[m
 	assert(!m_levels.empty());[m
 }[m
[36m@@ -62,7 +63,7 @@[m [mvoid LevelManager::startLevel()[m
 	if (m_currentLevelIt != m_levels.end())[m
 	{[m
 		std::function<void()> onLevelEnd = std::bind(&LevelManager::onLevelEnd, this);[m
[31m-		m_currentLevel = make_unique<Level>(*m_currentLevelIt, m_visuals, onLevelEnd);[m
[32m+[m		[32mm_currentLevel = make_unique<Level>(*m_currentLevelIt, m_visuals, onLevelEnd, m_soundPlayer);[m
 	}[m
 	else[m
 	{[m
[1mdiff --git a/src/LevelManager.h b/src/LevelManager.h[m
[1mindex 14ce434..c097e75 100644[m
[1m--- a/src/LevelManager.h[m
[1m+++ b/src/LevelManager.h[m
[36m@@ -2,11 +2,12 @@[m
 [m
 #include "Screen.h"[m
 #include "Level.h"[m
[32m+[m[32m#include "SoundPlayer.h"[m
 [m
 class LevelManager : public Screen[m
 {[m
 public:[m
[31m-	LevelManager(const std::vector<Level::Params> & levels, Level::Visuals levelVisuals, std::function<void()> onGameEnd);[m
[32m+[m	[32mLevelManager(const std::vector<Level::Params> & levels, Level::Visuals levelVisuals, std::function<void()> onGameEnd, SoundPlayer * m_soundPlayer);[m
 [m
 	void update(double delta) override;[m
 	void draw(Renderer * renderer) override;[m
[36m@@ -28,4 +29,6 @@[m [mprivate:[m
 	std::function<void()> c_onGameEnd;[m
 [m
 	std::vector<Level::Params>::iterator m_currentLevelIt;[m
[32m+[m
[32m+[m	[32mSoundPlayer * m_soundPlayer;[m
 };[m
\ No newline at end of file[m
[1mdiff --git a/src/Textures.h b/src/Textures.h[m
[1mindex ff6d97f..cdda53b 100644[m
[1m--- a/src/Textures.h[m
[1m+++ b/src/Textures.h[m
[36m@@ -1,8 +1,8 @@[m
 #pragma once[m
 [m
[31m-enum TextureId {	NONE, [m
[31m-					BASIC_0, STRONG_1, STRONG_0, [m
[31m-					BALL, [m
[31m-					PADDLE, [m
[31m-					LEVEL_0, LEVEL_1,[m
[31m-					PLAY, PLAY_SEL, CREDITS, CREDITS_SEL, EXIT, EXIT_SEL };[m
\ No newline at end of file[m
[32m+[m[32menum class TextureId {	NONE,[m[41m [m
[32m+[m						[32mBASIC_0, STRONG_1, STRONG_0,[m[41m [m
[32m+[m						[32mBALL,[m[41m [m
[32m+[m						[32mPADDLE,[m[41m [m
[32m+[m						[32mLEVEL_0, LEVEL_1,[m
[32m+[m						[32mPLAY, PLAY_SEL, CREDITS, CREDITS_SEL, EXIT, EXIT_SEL };[m
\ No newline at end of file[m
[1mdiff --git a/src/TileMatrix.cpp b/src/TileMatrix.cpp[m
[1mindex bdcb92c..931fc32 100644[m
[1m--- a/src/TileMatrix.cpp[m
[1m+++ b/src/TileMatrix.cpp[m
[36m@@ -21,7 +21,7 @@[m [mTileMatrix::TileMatrix(const ofImage & descriptor)[m
 [m
 			if (color == emptyColor)[m
 			{[m
[31m-				matrix.push_back(TileType::EMPTY); continue;[m
[32m+[m				[32mmatrix.push_back(TileType::NONE); continue;[m
 			}[m
 			if (color == basicColor)[m
 			{[m
[1mdiff --git a/src/TileMatrix.h b/src/TileMatrix.h[m
[1mindex e6c6e4a..dfb4e69 100644[m
[1m--- a/src/TileMatrix.h[m
[1m+++ b/src/TileMatrix.h[m
[36m@@ -1,11 +1,11 @@[m
 #pragma once[m
 [m
 #include "ofImage.h"[m
[32m+[m[32m#include "TileType.h"[m
 [m
 class TileMatrix[m
 {[m
 public:[m
[31m-	enum TileType { EMPTY, BASIC, STRONG };[m
 [m
 	TileMatrix(const ofImage & descriptor);[m
 [m
[1mdiff --git a/src/TileType.h b/src/TileType.h[m
[1mindex 477f9b4..ae87a7d 100644[m
[1m--- a/src/TileType.h[m
[1m+++ b/src/TileType.h[m
[36m@@ -1,3 +1,3 @@[m
 #pragma once[m
 [m
[31m-enum class TileType { BASIC, STRONG };[m
\ No newline at end of file[m
[32m+[m[32menum class TileType { NONE, BASIC, STRONG };[m
\ No newline at end of file[m
[1mdiff --git a/src/ofApp.cpp b/src/ofApp.cpp[m
[1mindex aee96b9..8d09d4d 100644[m
[1m--- a/src/ofApp.cpp[m
[1m+++ b/src/ofApp.cpp[m
[36m@@ -8,7 +8,8 @@[m [mofApp::ofApp()[m
 	:[m
 	m_levelAspect(1),[m
 	m_screen(nullptr),[m
[31m-	keyboard({ 'w', 'a', 's', 'd', ' ' })[m
[32m+[m	[32mkeyboard({ 'w', 'a', 's', 'd', ' ' }),[m
[32m+[m	[32msoundPlayer(&sounds)[m
 {[m
 }[m
 [m
[36m@@ -78,7 +79,7 @@[m [mvoid ofApp::setup(){[m
 	paramsVec.push_back(params);[m
 [m
 	std::function<void()> onGameEnd = std::bind(&ofApp::onGameEnd, this);[m
[31m-	levels = make_unique<LevelManager>(paramsVec, visuals, onGameEnd);[m
[32m+[m	[32mlevels = make_unique<LevelManager>(paramsVec, visuals, onGameEnd, &soundPlayer);[m
 [m
 	// first screen is the main menu[m
 	m_screen = menu.get();[m
[1mdiff --git a/src/ofApp.h b/src/ofApp.h[m
[1mindex adae302..98412ac 100644[m
[1m--- a/src/ofApp.h[m
[1m+++ b/src/ofApp.h[m
[36m@@ -33,9 +33,13 @@[m [mprivate:[m
 		void onGameEnd();[m
 [m
 		GameTextures textures;[m
[32m+[m		[32mstd::unique_ptr<Renderer> renderer;[m
[32m+[m
[32m+[m		[32mGameSounds sounds;[m
[32m+[m		[32mSoundPlayer soundPlayer;[m
[32m+[m
 		Keyboard keyboard;[m
 [m
[31m-		std::unique_ptr<Renderer> renderer;[m
 		std::unique_ptr<LevelManager> levels;[m
 		std::unique_ptr<MainMenu> menu;[m
 [m
