cmake_minimum_required(VERSION 3.0)

project(src ASM)

set(FPFNA_SOURCES
	"Collision/Collision.cs"
	"Collision/Distance.cs"
	"Collision/DynamicTree.cs"
	"Collision/DynamicTreeBroadPhase.cs"
	"Collision/IBroadPhase.cs"
	"Collision/Shapes/ChainShape.cs"
	"Collision/Shapes/CircleShape.cs"
	"Collision/Shapes/EdgeShape.cs"
	"Collision/Shapes/PolygonShape.cs"
	"Collision/Shapes/Shape.cs"
	"Collision/TimeOfImpact.cs"
	"Common/ConvexHull/ChainHull.cs"
	"Common/ConvexHull/GiftWrap.cs"
	"Common/ConvexHull/Melkman.cs"
	"Common/Decomposition/BayazitDecomposer.cs"
	"Common/Decomposition/CDTDecomposer.cs"
	"Common/Decomposition/CDT/Delaunay/DelaunayTriangle.cs"
	"Common/Decomposition/CDT/Delaunay/Sweep/AdvancingFront.cs"
	"Common/Decomposition/CDT/Delaunay/Sweep/AdvancingFrontNode.cs"
	"Common/Decomposition/CDT/Delaunay/Sweep/DTSweep.cs"
	"Common/Decomposition/CDT/Delaunay/Sweep/DTSweepConstraint.cs"
	"Common/Decomposition/CDT/Delaunay/Sweep/DTSweepContext.cs"
	"Common/Decomposition/CDT/Delaunay/Sweep/DTSweepPointComparator.cs"
	"Common/Decomposition/CDT/Delaunay/Sweep/PointOnEdgeException.cs"
	"Common/Decomposition/CDT/ITriangulatable.cs"
	"Common/Decomposition/CDT/Orientation.cs"
	"Common/Decomposition/CDT/Polygon/Polygon.cs"
	"Common/Decomposition/CDT/Polygon/PolygonPoint.cs"
	"Common/Decomposition/CDT/Polygon/PolygonSet.cs"
	"Common/Decomposition/CDT/Sets/ConstrainedPointSet.cs"
	"Common/Decomposition/CDT/Sets/PointSet.cs"
	"Common/Decomposition/CDT/TriangulationConstraint.cs"
	"Common/Decomposition/CDT/TriangulationContext.cs"
	"Common/Decomposition/CDT/TriangulationMode.cs"
	"Common/Decomposition/CDT/TriangulationPoint.cs"
	"Common/Decomposition/CDT/TriangulationUtil.cs"
	"Common/Decomposition/CDT/Util/FixedArray3.cs"
	"Common/Decomposition/CDT/Util/FixedBitArray3.cs"
	"Common/Decomposition/CDT/Util/PointGenerator.cs"
	"Common/Decomposition/CDT/Util/PolygonGenerator.cs"
	"Common/Decomposition/EarclipDecomposer.cs"
	"Common/Decomposition/FlipcodeDecomposer.cs"
	"Common/Decomposition/SeidelDecomposer.cs"
	"Common/Decomposition/Seidel/Edge.cs"
	"Common/Decomposition/Seidel/MonotoneMountain.cs"
	"Common/Decomposition/Seidel/Node.cs"
	"Common/Decomposition/Seidel/Point.cs"
	"Common/Decomposition/Seidel/QueryGraph.cs"
	"Common/Decomposition/Seidel/Sink.cs"
	"Common/Decomposition/Seidel/Trapezoid.cs"
	"Common/Decomposition/Seidel/TrapezoidalMap.cs"
	"Common/Decomposition/Seidel/Triangulator.cs"
	"Common/Decomposition/Seidel/XNode.cs"
	"Common/Decomposition/Seidel/YNode.cs"
	"Common/Decomposition/Triangulate.cs"
	"Common/FixedArray.cs"
	"Common/LineTools.cs"
	"Common/Math.cs"
	"Common/Path.cs"
	"Common/PathManager.cs"
	"Common/PhysicsLogic/FilterData.cs"
	"Common/PhysicsLogic/PhysicsLogic.cs"
	"Common/PhysicsLogic/RealExplosion.cs"
	"Common/PhysicsLogic/SimpleExplosion.cs"
	"Common/PolygonManipulation/CuttingTools.cs"
	"Common/PolygonManipulation/SimpleCombiner.cs"
	"Common/PolygonManipulation/SimplifyTools.cs"
	"Common/PolygonManipulation/YuPengClipper.cs"
	"Common/PolygonTools.cs"
	"Common/Serialization.cs"
	"Common/TextureTools/MarchingSquares.cs"
	"Common/TextureTools/Terrain.cs"
	"Common/TextureTools/TextureConverter.cs"
	"Common/Vertices.cs"
	"Controllers/AbstractForceController.cs"
	"Controllers/BuoyancyController.cs"
	"Controllers/Controller.cs"
	"Controllers/GravityController.cs"
	"Controllers/SimpleWindForce.cs"
	"Controllers/VelocityLimitController.cs"
	"ConvertUnits.cs"
	"DebugViewBase.cs"
	"Dynamics/Body.cs"
	"Dynamics/BreakableBody.cs"
	"Dynamics/ContactManager.cs"
	"Dynamics/Contacts/Contact.cs"
	"Dynamics/Contacts/ContactSolver.cs"
	"Dynamics/Fixture.cs"
	"Dynamics/Island.cs"
	"Dynamics/Joints/AngleJoint.cs"
	"Dynamics/Joints/DistanceJoint.cs"
	"Dynamics/Joints/FixedMouseJoint.cs"
	"Dynamics/Joints/FrictionJoint.cs"
	"Dynamics/Joints/GearJoint.cs"
	"Dynamics/Joints/Joint.cs"
	"Dynamics/Joints/MotorJoint.cs"
	"Dynamics/Joints/PrismaticJoint.cs"
	"Dynamics/Joints/PulleyJoint.cs"
	"Dynamics/Joints/RevoluteJoint.cs"
	"Dynamics/Joints/RopeJoint.cs"
	"Dynamics/Joints/WeldJoint.cs"
	"Dynamics/Joints/WheelJoint.cs"
	"Dynamics/TimeStep.cs"
	"Dynamics/World.cs"
	"Dynamics/WorldCallbacks.cs"
	"Factories/BodyFactory.cs"
	"Factories/FixtureFactory.cs"
	"Factories/JointFactory.cs"
	"Factories/LinkFactory.cs"
	"Properties/AssemblyInfo.cs"
	"Settings.cs"
)

if("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
  set(MONO_RELEASE_TYPE debug)
  set(FPFNA_DEFINES DEBUG TRACE)
else()
  set(MONO_RELEASE_TYPE optimize)
  set(FPFNA_DEFINES TRACE)
endif()

set(FPFNA_REFERENCES
    System.dll
    System.Xml.dll
)

set(LIBRARY_NAME FarseerPhysicsFna)
# Full library
compile_mono_assembly_aot(
    ASSEMBLY ${LIBRARY_NAME}
    SOURCES ${FPFNA_SOURCES}
    DEFINES ${FPFNA_DEFINES}
    REFERENCES ${FPFNA_REFERENCES} FNA.dll
    FLAGS unsafe ${MONO_RELEASE_TYPE}
)
add_library(VML${LIBRARY_NAME} STATIC
    ${LIBRARY_NAME}.c
    ${LIBRARY_NAME}.dll.s
)

# No Theorafile
compile_mono_assembly_aot(
    ASSEMBLY ${LIBRARY_NAME}.NoTheora
    SOURCES ${FPFNA_SOURCES}
    DEFINES ${FPFNA_DEFINES}
    REFERENCES ${FPFNA_REFERENCES} FNA.NoTheora.dll
    FLAGS unsafe ${MONO_RELEASE_TYPE}
)
add_library(VML${LIBRARY_NAME} STATIC
    ${LIBRARY_NAME}_NoTheora.c
    ${LIBRARY_NAME}.dll.s
)

# No Song
compile_mono_assembly_aot(
    ASSEMBLY ${LIBRARY_NAME}.NoSong
    SOURCES ${FPFNA_SOURCES}
    DEFINES ${FPFNA_DEFINES}
    REFERENCES ${FPFNA_REFERENCES} FNA.NoSong.dll
    FLAGS unsafe ${MONO_RELEASE_TYPE}
)
add_library(VML${LIBRARY_NAME}_NoSong STATIC
    ${LIBRARY_NAME}.c
    ${LIBRARY_NAME}.dll.s
)

# No Theorafile and no song
compile_mono_assembly_aot(
    ASSEMBLY ${LIBRARY_NAME}.NoTheora.NoSong
    SOURCES ${FPFNA_SOURCES}
    DEFINES ${FPFNA_DEFINES}
    REFERENCES ${FPFNA_REFERENCES} FNA.NoTheora.NoSong.dll
    FLAGS unsafe ${MONO_RELEASE_TYPE}
)
add_library(VML${LIBRARY_NAME}_NoTheora_NoSong STATIC
    ${LIBRARY_NAME}.c
    ${LIBRARY_NAME}.dll.s
)

add_dependencies(VML${LIBRARY_NAME} FPFNADependencies FPFNADependencies_Full)
add_dependencies(VML${LIBRARY_NAME} FPFNADependencies FPFNADependencies_NoTheora)
add_dependencies(VML${LIBRARY_NAME} FPFNADependencies FPFNADependencies_NoSong)
add_dependencies(VML${LIBRARY_NAME} FPFNADependencies FPFNADependencies_NoTheora_NoSong)

install(
  TARGETS
  	VML${LIBRARY_NAME}
	VML${LIBRARY_NAME}_NoTheora
	VML${LIBRARY_NAME}_NoSong
	VML${LIBRARY_NAME}_NoTheora_NoSong
  DESTINATION lib
)

install(
  FILES 
    ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}.dll
	${CMAKE_BINARY_DIR}/${LIBRARY_NAME}.NoTheora.dll
	${CMAKE_BINARY_DIR}/${LIBRARY_NAME}.NoSong.dll
	${CMAKE_BINARY_DIR}/${LIBRARY_NAME}.NoTheora.NoSong.dll
  DESTINATION lib/mono
)

install(
  FILES ${LIBRARY_NAME}.h 
  DESTINATION include/VML
)