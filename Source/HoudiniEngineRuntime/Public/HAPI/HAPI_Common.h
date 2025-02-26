/*
 * PROPRIETARY INFORMATION.  This software is proprietary to
 * Side Effects Software Inc., and is not to be reproduced,
 * transmitted, or disclosed in any way without written permission.
 *
 * Produced by:
 *      Side Effects Software Inc
 *      123 Front Street West, Suite 1401
 *      Toronto, Ontario
 *      Canada   M5J 2M2
 *      416-504-9876
 *
 * COMMENTS:
 */

#ifndef __HAPI_COMMON_h__
#define __HAPI_COMMON_h__

#include "HAPI_API.h"

/////////////////////////////////////////////////////////////////////////////
// Defines

#define HAPI_POSITION_VECTOR_SIZE           3
#define HAPI_SCALE_VECTOR_SIZE              3
#define HAPI_NORMAL_VECTOR_SIZE             3
#define HAPI_QUATERNION_VECTOR_SIZE         4
#define HAPI_EULER_VECTOR_SIZE              3
#define HAPI_UV_VECTOR_SIZE                 2
#define HAPI_COLOR_VECTOR_SIZE              4
#define HAPI_CV_VECTOR_SIZE                 4

#define HAPI_PRIM_MIN_VERTEX_COUNT          1
#define HAPI_PRIM_MAX_VERTEX_COUNT          16

#define HAPI_INVALID_PARM_ID                -1

/// Common Default Attributes' Names
/// @{
#define HAPI_ATTRIB_POSITION                "P"
#define HAPI_ATTRIB_UV                      "uv"
#define HAPI_ATTRIB_UV2                     "uv2"
#define HAPI_ATTRIB_NORMAL                  "N"
#define HAPI_ATTRIB_TANGENT                 "tangentu"
#define HAPI_ATTRIB_TANGENT2                "tangentv"
#define HAPI_ATTRIB_COLOR                   "Cd"
#define HAPI_ATTRIB_NAME                    "name"
/// @}

/// This is the name of the primitive group created from all the primitives
/// that are not in any user-defined group. This way, when you put all the
/// groups together you cover the entire mesh. This is important for some
/// clients where the mesh has to be defined in terms of submeshes that cover
/// the entire original mesh.
#define HAPI_UNGROUPED_GROUP_NAME           "__ungrouped_group"

/// Common image file format names (to use with the material extract APIs).
/// Note that you may still want to check if they are supported via
/// HAPI_GetSupportedImageFileFormats() since all formats are loaded
/// dynamically by Houdini on-demand so just because these formats are defined
/// here doesn't mean they are supported in your instance.
/// @{
#define HAPI_RAW_FORMAT_NAME                "HAPI_RAW" // HAPI-only Raw Format
#define HAPI_PNG_FORMAT_NAME                "PNG"
#define HAPI_JPEG_FORMAT_NAME               "JPEG"
#define HAPI_BMP_FORMAT_NAME                "Bitmap"
#define HAPI_TIFF_FORMAT_NAME               "TIFF"
#define HAPI_TGA_FORMAT_NAME                "Targa"
/// @}

/// Default image file format's name - used when the image generated and has
/// no "original" file format and the user does not specify a format to
/// convert to.
#define HAPI_DEFAULT_IMAGE_FORMAT_NAME      HAPI_PNG_FORMAT_NAME

/// Name of subnet OBJ node containing the global nodes.
#define HAPI_GLOBAL_NODES_NODE_NAME         "GlobalNodes"

/// [HAPI_CACHE]
/// Common cache names. You can see these same cache names in the
/// Cache Manager window in Houdini (Windows > Cache Manager).
#define HAPI_CACHE_COP_COOK                 "COP Cook Cache"
#define HAPI_CACHE_COP_FLIPBOOK             "COP Flipbook Cache"
#define HAPI_CACHE_IMAGE                    "Image Cache"
#define HAPI_CACHE_OBJ                      "Object Transform Cache"
#define HAPI_CACHE_GL_TEXTURE               "OpenGL Texture Cache"
#define HAPI_CACHE_GL_VERTEX                "OpenGL Vertex Cache"
#define HAPI_CACHE_SOP                      "SOP Cache"
#define HAPI_CACHE_VEX                      "VEX File Cache"
/// [HAPI_CACHE]

/// Environment variables.
#define HAPI_ENV_HIP                        "HIP"
#define HAPI_ENV_JOB                        "JOB"
#define HAPI_ENV_CLIENT_NAME                "HAPI_CLIENT_NAME"

// Make sure our enums and structs are usable without those keywords, as-is,
// in C.
#ifdef __cplusplus
    #define HAPI_C_ENUM_TYPEDEF( enum_name )
    #define HAPI_C_STRUCT_TYPEDEF( struct_name )
#else
    #define HAPI_C_ENUM_TYPEDEF( enum_name ) \
        typedef enum enum_name enum_name;
    #define HAPI_C_STRUCT_TYPEDEF( struct_name ) \
        typedef struct struct_name struct_name;
#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
// Typedefs

// C has no bool.
#ifdef __cplusplus
    typedef bool HAPI_Bool;
#else
    typedef char HAPI_Bool;
#endif // __cplusplus

#ifdef _WIN32
    typedef unsigned int HAPI_ProcessId;
#else
    typedef int HAPI_ProcessId;
#endif

/// Has to be 64-bit. Should be on all reasonable platforms...but we make sure.
typedef long long HAPI_SessionId;
HAPI_STATIC_ASSERT( sizeof( HAPI_SessionId ) == 8, unsupported_size_of_long );

/// Use this with HAPI_GetString() to get the value.
/// See @ref HAPI_Fundamentals_Strings.
typedef int HAPI_StringHandle;

typedef int HAPI_AssetLibraryId;
typedef int HAPI_AssetId;

/// See @ref HAPI_Nodes_Basics.
typedef int HAPI_NodeId;

/// Either get this from the ::HAPI_ParmInfo or ::HAPI_GetParmIdFromName().
/// See @ref HAPI_Parameters.
typedef int HAPI_ParmId;

/// Use this with ::HAPI_GetObjects().
/// See @ref HAPI_ObjectsGeosParts_Objects.
typedef int HAPI_ObjectId;

/// Use this with ::HAPI_GetGeoInfo().
/// See @ref HAPI_ObjectsGeosParts_Geos.
typedef int HAPI_GeoId;

/// Use this with ::HAPI_GetPartInfo().
/// See @ref HAPI_ObjectsGeosParts_Parts.
typedef int HAPI_PartId;

typedef int HAPI_MaterialId;

/////////////////////////////////////////////////////////////////////////////
// Enums

enum HAPI_License
{
    HAPI_LICENSE_NONE,
    HAPI_LICENSE_HOUDINI_ENGINE,
    HAPI_LICENSE_HOUDINI,
    HAPI_LICENSE_HOUDINI_FX,
    HAPI_LICENSE_HOUDINI_ENGINE_INDIE,
    HAPI_LICENSE_HOUDINI_INDIE,
    HAPI_LICENSE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_License )

enum HAPI_StatusType
{
    HAPI_STATUS_CALL_RESULT,
    HAPI_STATUS_COOK_RESULT,
    HAPI_STATUS_COOK_STATE,
    HAPI_STATUS_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_StatusType )

enum HAPI_StatusVerbosity
{
    HAPI_STATUSVERBOSITY_0,
    HAPI_STATUSVERBOSITY_1,
    HAPI_STATUSVERBOSITY_2,

    HAPI_STATUSVERBOSITY_ALL = HAPI_STATUSVERBOSITY_2,
                                ///< Equilvalent to ::HAPI_STATUSVERBOSITY_2.

    // Used for Results.
    HAPI_STATUSVERBOSITY_ERRORS = HAPI_STATUSVERBOSITY_0,
                                ///< Equilvalent to ::HAPI_STATUSVERBOSITY_0.
    HAPI_STATUSVERBOSITY_WARNINGS = HAPI_STATUSVERBOSITY_1,
                                ///< Equilvalent to ::HAPI_STATUSVERBOSITY_1.
    HAPI_STATUSVERBOSITY_MESSAGES = HAPI_STATUSVERBOSITY_2,
                                ///< Equilvalent to ::HAPI_STATUSVERBOSITY_2.
};
HAPI_C_ENUM_TYPEDEF( HAPI_StatusVerbosity )

enum HAPI_Result
{
    HAPI_RESULT_SUCCESS                                 = 0,
    HAPI_RESULT_FAILURE                                 = 1,
    HAPI_RESULT_ALREADY_INITIALIZED                     = 2,
    HAPI_RESULT_NOT_INITIALIZED                         = 3,
    HAPI_RESULT_CANT_LOADFILE                           = 4,
    HAPI_RESULT_PARM_SET_FAILED                         = 5,
    HAPI_RESULT_INVALID_ARGUMENT                        = 6,
    HAPI_RESULT_CANT_LOAD_GEO                           = 7,
    HAPI_RESULT_CANT_GENERATE_PRESET                    = 8,
    HAPI_RESULT_CANT_LOAD_PRESET                        = 9,
    HAPI_RESULT_ASSET_DEF_ALREADY_LOADED                = 10,

    HAPI_RESULT_NO_LICENSE_FOUND                        = 110,
    HAPI_RESULT_DISALLOWED_NC_LICENSE_FOUND             = 120,
    HAPI_RESULT_DISALLOWED_NC_ASSET_WITH_C_LICENSE      = 130,
    HAPI_RESULT_DISALLOWED_NC_ASSET_WITH_LC_LICENSE     = 140,
    HAPI_RESULT_DISALLOWED_LC_ASSET_WITH_C_LICENSE      = 150,
    HAPI_RESULT_DISALLOWED_HENGINEINDIE_W_3PARTY_PLUGIN = 160,

    HAPI_RESULT_ASSET_INVALID                           = 200,
    HAPI_RESULT_NODE_INVALID                            = 210,

    HAPI_RESULT_USER_INTERRUPTED                        = 300,

    HAPI_RESULT_INVALID_SESSION                         = 400
};
HAPI_C_ENUM_TYPEDEF( HAPI_Result )

enum HAPI_SessionType
{
    HAPI_SESSION_INPROCESS,
    HAPI_SESSION_THRIFT,
    HAPI_SESSION_CUSTOM1,
    HAPI_SESSION_CUSTOM2,
    HAPI_SESSION_CUSTOM3,
    HAPI_SESSION_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_SessionType )

enum HAPI_State
{
    HAPI_STATE_READY, ///< Everything cook successfully without errors.
    HAPI_STATE_READY_WITH_FATAL_ERRORS, ///< You should abort the cook.
    HAPI_STATE_READY_WITH_COOK_ERRORS, ///< Only some objects failed.
    HAPI_STATE_STARTING_COOK,
    HAPI_STATE_COOKING,
    HAPI_STATE_STARTING_LOAD,
    HAPI_STATE_LOADING,
    HAPI_STATE_MAX,

    HAPI_STATE_MAX_READY_STATE = HAPI_STATE_READY_WITH_COOK_ERRORS
};
HAPI_C_ENUM_TYPEDEF( HAPI_State )

enum HAPI_PackedPrimInstancingMode
{
    HAPI_PACKEDPRIM_INSTANCING_MODE_INVALID = -1,
    HAPI_PACKEDPRIM_INSTANCING_MODE_DISABLED,
    HAPI_PACKEDPRIM_INSTANCING_MODE_HIERARCHY,
    HAPI_PACKEDPRIM_INSTANCING_MODE_FLAT,
    HAPI_PACKEDPRIM_INSTANCING_MODE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_PackedPrimInstancingMode )

enum HAPI_Permissions
{
    HAPI_PERMISSIONS_NON_APPLICABLE,
    HAPI_PERMISSIONS_READ_WRITE,
    HAPI_PERMISSIONS_READ_ONLY,
    HAPI_PERMISSIONS_WRITE_ONLY,
    HAPI_PERMISSIONS_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_Permissions )

enum HAPI_RampType
{
    HAPI_RAMPTYPE_INVALID = -1,
    HAPI_RAMPTYPE_FLOAT,
    HAPI_RAMPTYPE_COLOR,
    HAPI_RAMPTYPE_MAX,
};
HAPI_C_ENUM_TYPEDEF( HAPI_RampType )

/// As you can see, some of these high level types share the same underlying
/// raw data type. For instance, both string and file parameter types can be
/// represented with strings, yet semantically they are different. We will
/// group high level parameter types that share an underlying raw data type
/// together, so you can alway check the raw data type of a parameter based
/// on its high level data type by checking a range of values.
enum HAPI_ParmType
{
    HAPI_PARMTYPE_INT = 0,
    HAPI_PARMTYPE_MULTIPARMLIST,
    HAPI_PARMTYPE_TOGGLE,
    HAPI_PARMTYPE_BUTTON,

    HAPI_PARMTYPE_FLOAT,
    HAPI_PARMTYPE_COLOR,

    HAPI_PARMTYPE_STRING,
    HAPI_PARMTYPE_PATH_FILE,
    HAPI_PARMTYPE_PATH_FILE_GEO,
    HAPI_PARMTYPE_PATH_FILE_IMAGE,
    HAPI_PARMTYPE_PATH_NODE,

    HAPI_PARMTYPE_FOLDERLIST,

    HAPI_PARMTYPE_FOLDER,
    HAPI_PARMTYPE_LABEL,
    HAPI_PARMTYPE_SEPARATOR,

    // Helpers

    HAPI_PARMTYPE_MAX, ///< Total number of supported parameter types.

    HAPI_PARMTYPE_INT_START         = HAPI_PARMTYPE_INT,
    HAPI_PARMTYPE_INT_END           = HAPI_PARMTYPE_BUTTON,

    HAPI_PARMTYPE_FLOAT_START       = HAPI_PARMTYPE_FLOAT,
    HAPI_PARMTYPE_FLOAT_END         = HAPI_PARMTYPE_COLOR,

    HAPI_PARMTYPE_STRING_START      = HAPI_PARMTYPE_STRING,
    HAPI_PARMTYPE_STRING_END        = HAPI_PARMTYPE_PATH_NODE,

    HAPI_PARMTYPE_PATH_START        = HAPI_PARMTYPE_PATH_FILE,
    HAPI_PARMTYPE_PATH_END          = HAPI_PARMTYPE_PATH_NODE,

    HAPI_PARMTYPE_PATH_FILE_START   = HAPI_PARMTYPE_PATH_FILE,
    HAPI_PARMTYPE_PATH_FILE_END     = HAPI_PARMTYPE_PATH_FILE_IMAGE,

    HAPI_PARMTYPE_PATH_NODE_START   = HAPI_PARMTYPE_PATH_NODE,
    HAPI_PARMTYPE_PATH_NODE_END     = HAPI_PARMTYPE_PATH_NODE,

    HAPI_PARMTYPE_CONTAINER_START   = HAPI_PARMTYPE_FOLDERLIST,
    HAPI_PARMTYPE_CONTAINER_END     = HAPI_PARMTYPE_FOLDERLIST,

    HAPI_PARMTYPE_NONVALUE_START    = HAPI_PARMTYPE_FOLDER,
    HAPI_PARMTYPE_NONVALUE_END      = HAPI_PARMTYPE_SEPARATOR
};
HAPI_C_ENUM_TYPEDEF( HAPI_ParmType )

enum HAPI_ChoiceListType
{
    HAPI_CHOICELISTTYPE_NONE, ///< Parameter is not a menu.
    HAPI_CHOICELISTTYPE_NORMAL, ///< Menu Only, Single Selection
    HAPI_CHOICELISTTYPE_MINI, ///< Mini Menu Only, Single Selection
    HAPI_CHOICELISTTYPE_REPLACE, ///< Field + Single Selection Menu
    HAPI_CHOICELISTTYPE_TOGGLE ///< Field + Multiple Selection Menu
};
HAPI_C_ENUM_TYPEDEF( HAPI_ChoiceListType )

enum HAPI_PresetType
{
    HAPI_PRESETTYPE_INVALID = -1,
    HAPI_PRESETTYPE_BINARY = 0, ///< Just the presets binary blob.
    HAPI_PRESETTYPE_IDX, ///< Presets blob within an .idx file format.
    HAPI_PRESETTYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_PresetType )

enum HAPI_AssetType
{
    HAPI_ASSETTYPE_INVALID = -1,
    HAPI_ASSETTYPE_OBJ = 0,
    HAPI_ASSETTYPE_SOP,
    HAPI_ASSETTYPE_POPNET,
    HAPI_ASSETTYPE_POP,
    HAPI_ASSETTYPE_CHOPNET,
    HAPI_ASSETTYPE_CHOP,
    HAPI_ASSETTYPE_ROP,
    HAPI_ASSETTYPE_SHOP,
    HAPI_ASSETTYPE_COP2,
    HAPI_ASSETTYPE_COPNET,
    HAPI_ASSETTYPE_VOP,
    HAPI_ASSETTYPE_VOPNET,
    HAPI_ASSETTYPE_DOP,
    HAPI_ASSETTYPE_MGR,
    HAPI_ASSETTYPE_DIR,
    HAPI_ASSETTYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_AssetType )

enum HAPI_AssetSubType
{
    HAPI_ASSETSUBTYPE_INVALID = -1,
    HAPI_ASSETSUBTYPE_DEFAULT,
    HAPI_ASSETSUBTYPE_CURVE,
    HAPI_ASSETSUBTYPE_INPUT,
    HAPI_ASSETSUBTYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_AssetSubType )

enum HAPI_GroupType
{
    HAPI_GROUPTYPE_INVALID = -1,
    HAPI_GROUPTYPE_POINT,
    HAPI_GROUPTYPE_PRIM,
    HAPI_GROUPTYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_GroupType )

enum HAPI_AttributeOwner
{
    HAPI_ATTROWNER_INVALID = -1,
    HAPI_ATTROWNER_VERTEX,
    HAPI_ATTROWNER_POINT,
    HAPI_ATTROWNER_PRIM,
    HAPI_ATTROWNER_DETAIL,
    HAPI_ATTROWNER_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_AttributeOwner )

enum HAPI_CurveType
{
    HAPI_CURVETYPE_INVALID = -1,
    HAPI_CURVETYPE_LINEAR,
    HAPI_CURVETYPE_NURBS,
    HAPI_CURVETYPE_BEZIER,
    HAPI_CURVETYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_CurveType )

enum HAPI_VolumeType
{
    HAPI_VOLUMETYPE_INVALID = -1,
    HAPI_VOLUMETYPE_HOUDINI,
    HAPI_VOLUMETYPE_VDB,
    HAPI_VOLUMETYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_VolumeType )

enum HAPI_StorageType
{
    HAPI_STORAGETYPE_INVALID = -1,
    HAPI_STORAGETYPE_INT,
    HAPI_STORAGETYPE_FLOAT,
    HAPI_STORAGETYPE_STRING,
    HAPI_STORAGETYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_StorageType )

enum HAPI_GeoType
{
    HAPI_GEOTYPE_INVALID = -1,

    /// Most geos will be of this type which essentially means a geo
    /// not of the other types.
    HAPI_GEOTYPE_DEFAULT,

    /// An exposed edit node.
    /// See @ref HAPI_IntermediateAssetsResults.
    HAPI_GEOTYPE_INTERMEDIATE,

    /// An input geo that can accept geometry from the host.
    /// See @ref HAPI_AssetInputs_MarshallingGeometryIntoHoudini.
    HAPI_GEOTYPE_INPUT,

    /// A curve.
    /// See @ref HAPI_Curves.
    HAPI_GEOTYPE_CURVE,

    HAPI_GEOTYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_GeoType )

enum HAPI_PartType
{
    HAPI_PARTTYPE_INVALID = -1,
    HAPI_PARTTYPE_MESH,
    HAPI_PARTTYPE_CURVE,
    HAPI_PARTTYPE_VOLUME,
    HAPI_PARTTYPE_INSTANCER,
    HAPI_PARTTYPE_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_PartType )

enum HAPI_InputType
{
    HAPI_INPUT_INVALID = -1,
    HAPI_INPUT_TRANSFORM,
    HAPI_INPUT_GEOMETRY,
    HAPI_INPUT_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_InputType )

enum HAPI_CurveOrders
{
    HAPI_CURVE_ORDER_VARYING = 0,
    HAPI_CURVE_ORDER_INVALID = 1,
    HAPI_CURVE_ORDER_LINEAR = 2,
    HAPI_CURVE_ORDER_QUADRATIC = 3,
    HAPI_CURVE_ORDER_CUBIC = 4,
};
HAPI_C_ENUM_TYPEDEF( HAPI_CurveOrders )

enum HAPI_TransformComponent
{
    HAPI_TRANSFORM_TX = 0,
    HAPI_TRANSFORM_TY,
    HAPI_TRANSFORM_TZ,
    HAPI_TRANSFORM_RX,
    HAPI_TRANSFORM_RY,
    HAPI_TRANSFORM_RZ,
    HAPI_TRANSFORM_QX,
    HAPI_TRANSFORM_QY,
    HAPI_TRANSFORM_QZ,
    HAPI_TRANSFORM_QW,
    HAPI_TRANSFORM_SX,
    HAPI_TRANSFORM_SY,
    HAPI_TRANSFORM_SZ
};
HAPI_C_ENUM_TYPEDEF( HAPI_TransformComponent )

enum HAPI_RSTOrder
{
    HAPI_TRS = 0,
    HAPI_TSR,
    HAPI_RTS,
    HAPI_RST,
    HAPI_STR,
    HAPI_SRT,

    HAPI_RSTORDER_DEFAULT = HAPI_SRT
};
HAPI_C_ENUM_TYPEDEF( HAPI_RSTOrder )

enum HAPI_XYZOrder
{
    HAPI_XYZ = 0,
    HAPI_XZY,
    HAPI_YXZ,
    HAPI_YZX,
    HAPI_ZXY,
    HAPI_ZYX,

    HAPI_XYZORDER_DEFAULT = HAPI_XYZ
};
HAPI_C_ENUM_TYPEDEF( HAPI_XYZOrder )

enum HAPI_ImageDataFormat
{
    HAPI_IMAGE_DATA_UNKNOWN = -1,
    HAPI_IMAGE_DATA_INT8,
    HAPI_IMAGE_DATA_INT16,
    HAPI_IMAGE_DATA_INT32,
    HAPI_IMAGE_DATA_FLOAT16,
    HAPI_IMAGE_DATA_FLOAT32,
    HAPI_IMAGE_DATA_MAX,

    HAPI_IMAGE_DATA_DEFAULT = HAPI_IMAGE_DATA_INT8
};
HAPI_C_ENUM_TYPEDEF( HAPI_ImageDataFormat )

enum HAPI_ImagePacking
{
    HAPI_IMAGE_PACKING_UNKNOWN = -1,
    HAPI_IMAGE_PACKING_SINGLE,  ///< Single Channel
    HAPI_IMAGE_PACKING_DUAL,    ///< Dual Channel
    HAPI_IMAGE_PACKING_RGB,     ///< RGB
    HAPI_IMAGE_PACKING_BGR,     ///< RGB Reveresed
    HAPI_IMAGE_PACKING_RGBA,    ///< RGBA
    HAPI_IMAGE_PACKING_ABGR,    ///< RGBA Reversed
    HAPI_IMAGE_PACKING_MAX,

    HAPI_IMAGE_PACKING_DEFAULT3 = HAPI_IMAGE_PACKING_RGB,
    HAPI_IMAGE_PACKING_DEFAULT4 = HAPI_IMAGE_PACKING_RGBA
};
HAPI_C_ENUM_TYPEDEF( HAPI_ImagePacking )

/// This enum is to be used with ::HAPI_GetEnvInt() to retrieve basic
/// information about the HAPI implementation currently being linked
/// against. Note that as of HAPI version 2.0, these enum values are
/// guaranteed never to change so you can reliably get this information from
/// any post-2.0 version of HAPI. The same goes for the actual
/// ::HAPI_GetEnvInt() API call.
enum HAPI_EnvIntType
{
    HAPI_ENVINT_INVALID = -1,

    /// The three components of the Houdini version that HAPI is
    /// expecting to link against.
    /// @{
    HAPI_ENVINT_VERSION_HOUDINI_MAJOR = 100,
    HAPI_ENVINT_VERSION_HOUDINI_MINOR = 110,
    HAPI_ENVINT_VERSION_HOUDINI_BUILD = 120,
    HAPI_ENVINT_VERSION_HOUDINI_PATCH = 130,
    /// @}

    /// The two components of the Houdini Engine (marketed) version.
    /// @{
    HAPI_ENVINT_VERSION_HOUDINI_ENGINE_MAJOR = 200,
    HAPI_ENVINT_VERSION_HOUDINI_ENGINE_MINOR = 210,
    /// @}

    /// This is a monotonously increasing API version number that can be used
    /// to lock against a certain API for compatibility purposes. Basically,
    /// when this number changes code compiled against the HAPI.h methods
    /// might no longer compile. Semantic changes to the methods will also
    /// cause this version to increase. This number will be reset to 0
    /// every time the Houdini Engine version is bumped.
    HAPI_ENVINT_VERSION_HOUDINI_ENGINE_API = 220,

    HAPI_ENVINT_MAX,
};
HAPI_C_ENUM_TYPEDEF( HAPI_EnvIntType )

/// This enum is to be used with ::HAPI_GetSessionEnvInt() to retrieve basic
/// session-specific information.
enum HAPI_SessionEnvIntType
{
    HAPI_SESSIONENVINT_INVALID = -1,

    /// License Type. See ::HAPI_License.
    HAPI_SESSIONENVINT_LICENSE = 100,

    HAPI_SESSIONENVINT_MAX
};
HAPI_C_ENUM_TYPEDEF( HAPI_SessionEnvIntType )

/// [HAPI_CacheProperty]
enum HAPI_CacheProperty
{
    /// Current memory usage in MB. Setting this to 0 invokes
    /// a cache clear.
    HAPI_CACHEPROP_CURRENT,

    HAPI_CACHEPROP_HAS_MIN, ///< True if it actually has a minimum size.
    HAPI_CACHEPROP_MIN, ///< Min cache memory limit in MB.
    HAPI_CACHEPROP_HAS_MAX, ///< True if it actually has a maximum size.
    HAPI_CACHEPROP_MAX, ///< Max cache memory limit in MB.

    /// How aggressive to cull memory. This only works for:
    ///     - ::HAPI_CACHE_COP_COOK where:
    ///         0   ->  Never reduce inactive cache.
    ///         1   ->  Always reduce inactive cache.
    ///     - ::HAPI_CACHE_OBJ where:
    ///         0   ->  Never enforce the max memory limit.
    ///         1   ->  Always enforce the max memory limit.
    ///     - ::HAPI_CACHE_SOP where:
    ///         0   ->  When to Unload = Never
    ///                 When to Limit Max Memory = Never
    ///         1-2 ->  When to Unload = Based on Flag
    ///                 When to Limit Max Memory = Never
    ///         3-4 ->  When to Unload = Based on Flag
    ///                 When to Limit Max Memory = Always
    ///         5   ->  When to Unload = Always
    ///                 When to Limit Max Memory = Always
    HAPI_CACHEPROP_CULL_LEVEL,
};
/// [HAPI_CacheProperty]
HAPI_C_ENUM_TYPEDEF( HAPI_CacheProperty )

/////////////////////////////////////////////////////////////////////////////
// Main API Structs

// GENERICS -----------------------------------------------------------------

struct HAPI_API HAPI_Transform
{
    float   position[           HAPI_POSITION_VECTOR_SIZE ];
    float   rotationQuaternion[ HAPI_QUATERNION_VECTOR_SIZE ];
    float   scale[              HAPI_SCALE_VECTOR_SIZE ];

    HAPI_RSTOrder rstOrder;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_Transform )

struct HAPI_API HAPI_TransformEuler
{
    float   position[       HAPI_POSITION_VECTOR_SIZE ];
    float   rotationEuler[  HAPI_EULER_VECTOR_SIZE ];
    float   scale[          HAPI_SCALE_VECTOR_SIZE ];

    HAPI_XYZOrder rotationOrder;
    HAPI_RSTOrder rstOrder;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_TransformEuler )

// SESSIONS -----------------------------------------------------------------

struct HAPI_API HAPI_Session
{
    /// The type of session detemines the which implementation will be
    /// used to communicate with the Houdini Engine library.
    HAPI_SessionType type;

    /// Some session types support multiple simultanous sessions. This means
    /// that each session needs to have a unique identifier.
    HAPI_SessionId id;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_Session )

// TIME ---------------------------------------------------------------------

struct HAPI_API HAPI_TimelineOptions
{
    float fps;

    float startTime;
    float endTime;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_TimelineOptions )

// ASSETS -------------------------------------------------------------------

struct HAPI_API HAPI_AssetInfo
{
    HAPI_AssetId id;

    /// The houdini asset type. There may be all sorts of different assets
    /// in Houdini, corresponding to the type of data that flows in that
    /// particular type of data network. For the moment, the only supported
    /// types are OBJ and SOP assets, though this will change in the future
    /// to include a greater set.
    HAPI_AssetType type;

    /// Usually this will be ::HAPI_ASSETSUBTYPE_DEFAULT. The other values
    /// correspond to assets that weren't instantiated through the use of
    /// .otl files, such as curves.
    HAPI_AssetSubType subType;

    /// This id is primarily used to check whether the asset still exists
    /// within the Houdini scene running inside the runtime. The asset id
    /// alone is not enough as asset ids are re-used between sessions.
    /// We use this id to determine whether we need to re-instatiate an asset
    /// we have on the client side so that Houdini also knows about it -
    /// which is different from the case where a new asset is being loaded
    /// for the first time.
    ///
    /// The best example is saving and loading a scene in the host application.
    /// The host would need to restore the underlying Houdini scene. However,
    /// in the saved information, the host would have seemingly valid asset
    /// ids and would have no way of know if those ids are from the current
    /// session or a previous session. Using this validation id and
    /// HAPI_IsAssetValid(), the host can check if the asset ids it has are
    /// valid.
    int validationId;

    /// Use the node id to get the asset's parameters.
    /// See @ref HAPI_Nodes_Basics.
    HAPI_NodeId nodeId;

    /// The objectNodeId differs from the regular nodeId in that for
    /// geometry based assets (SOPs) it will be the node id of the dummy
    /// object (OBJ) node instead of the asset node. For object based assets
    /// the objectNodeId will equal the nodeId. The reason the distinction
    /// exists is because transforms are always stored on the object node
    /// but the asset parameters may not be on the asset node if the asset
    /// is a geometry asset so we need both.
    HAPI_NodeId objectNodeId;

    /// It's possible to instantiate an asset without cooking it.
    /// See @ref HAPI_Assets_Cooking.
    HAPI_Bool hasEverCooked;

    HAPI_StringHandle nameSH; ///< Instance name (the label + a number).
    HAPI_StringHandle labelSH; ///< This is what any end user should be shown.
    HAPI_StringHandle filePathSH; ///< Path to the .otl library file.
    HAPI_StringHandle versionSH; ///< User-defined asset version.
    HAPI_StringHandle fullOpNameSH; ///< Full asset name and namespace.
    HAPI_StringHandle helpTextSH; ///< Asset help marked-up text.

    int objectCount; ///< See @ref HAPI_ObjectsGeosParts_Objects.
    int handleCount; ///< See @ref HAPI_Handles.
    int editableNodeNetworkCount; ///< @ref HAPI_Nodes_EditableNodeNetworks.

    /// Transform inputs exposed by the asset. For OBJ assets this is the
    /// number of transform inputs on the OBJ node. For SOP assets, this is
    /// the singular transform input on the dummy wrapper OBJ node.
    /// See @ref HAPI_AssetInputs.
    int transformInputCount;

    /// Geometry inputs exposed by the asset. For OBJ assets this is the
    /// number of SOP-filtered node path parameters exposed plus the Object
    /// Merge SOPs inside marked as Editable Nodes. For SOP assets this is
    /// the number of geometry inputs on the SOP node itself plus SOP-filtered
    /// node path parameters exposed.
    /// See @ref HAPI_AssetInputs.
    int geoInputCount;

    /// For incremental updates. Indicates whether any of the assets's
    /// objects have changed. Refreshed only during an asset cook.
    HAPI_Bool haveObjectsChanged;

    /// For incremental updates. Indicates whether any of the asset's
    /// materials have changed. Refreshed only during an asset cook.
    HAPI_Bool haveMaterialsChanged;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_AssetInfo )

struct HAPI_API HAPI_CookOptions
{
    /// Normally, geos are split into parts in two different ways. First it
    /// is split by group and within each group it is split by primitive type.
    ///
    /// For example, if you have a geo with group1 covering half of the mesh
    /// and volume1 and group2 covering the other half of the mesh, all of
    /// curve1, and volume2 you will end up with 5 parts. First two parts
    /// will be for the half-mesh of group1 and volume1, and the last three
    /// will cover group2.
    ///
    /// This toggle lets you disable the splitting by group and just have
    /// the geo be split by primitive type alone. By default, this is true
    /// and therefore geos will be split by group and primitive type. If
    /// set to false, geos will only be split by primtive type.
    HAPI_Bool splitGeosByGroup;

    /// For meshes only, this is enforced by convexing the mesh. Use -1
    /// to avoid convexing at all and get some performance boost.
    int maxVerticesPerPrimitive;

    /// For curves only.
    /// If this is set to true, then all curves will be refined to a linear
    /// curve and you can no longer access the orginal cvs.  You can control
    /// the refinement detail via ::HAPI_CookOptions::curveRefineLOD.
    /// If it's false, the curve type (nurbs, bezier etc) will be left as is.
    HAPI_Bool refineCurveToLinear;

    /// Controls the number of dvisions per unit distance when refining
    /// a curve to linear.  The default in Houdini is 8.0.
    float curveRefineLOD;

    /// If this option is turned on, then we will recursively clear the
    /// errors and warnings (and messages) of all nodes before performing
    /// the cook.
    HAPI_Bool clearErrorsAndWarnings;

    /// Decide whether to recursively cook all templated geos or not.
    HAPI_Bool cookTemplatedGeos;

    /// Choose how you want the cook to handle packed primitives.
    /// The default is: ::HAPI_PACKEDPRIM_INSTANCING_MODE_DISABLED
    HAPI_PackedPrimInstancingMode packedPrimInstancingMode;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_CookOptions )

// NODES --------------------------------------------------------------------

struct HAPI_API HAPI_NodeInfo
{
    HAPI_NodeId id;
    HAPI_AssetId assetId;
    HAPI_StringHandle nameSH;

    /// Always true unless the asset's definition has changed due to loading
    /// a duplicate asset definition and from another otl asset library
    /// file OR deleting the otl asset library file used by this node's asset.
    HAPI_Bool isValid;

    /// Total number of cooks of this node.
    int totalCookCount;

    /// Use this unique id to grab the OP_Node pointer for this node.
    /// If you're linking against the C++ HDK, include the OP_Node.h header
    /// and call OP_Node::lookupNode().
    int uniqueHoudiniNodeId;

    /// This is the internal node path in the Houdini scene graph. This path
    /// is meant to be abstracted away for most client purposes but for
    /// advanced uses it can come in handy.
    HAPI_StringHandle internalNodePathSH;

    /// Total number of parameters this asset has exposed. Includes hidden
    /// parameters.
    /// See @ref HAPI_Parameters.
    int parmCount;

    /// Number of values. A single parameter may have more than one value so
    /// this number is more than or equal to ::HAPI_NodeInfo::parmCount.
    /// @{
    int parmIntValueCount;
    int parmFloatValueCount;
    int parmStringValueCount;
    /// @}

    /// The total number of choices among all the combo box parameters.
    /// See @ref HAPI_Parameters_ChoiceLists.
    int parmChoiceCount;

    /// The number of child nodes. This is 0 for all nodes that are not
    /// node networks.
    int childNodeCount;

    /// The number of inputs this specific node has.
    int inputCount;

    /// Nodes created via scripts or via ::HAPI_CreateNode() will be have
    /// this set to true. Only such nodes can be deleted using
    /// ::HAPI_DeleteNode().
    HAPI_Bool createdPostAssetLoad;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_NodeInfo )

// PARAMETERS ---------------------------------------------------------------

/// @struct HAPI_ParmInfo
///
/// Contains parameter information like name, label, type, and size.
///
struct HAPI_API HAPI_ParmInfo
{
    /// The parent id points to the id of the parent parm
    /// of this parm. The parent parm is something like a folder.
    HAPI_ParmId id;

    /// Parameter id of the parent of this parameter.
    HAPI_ParmId parentId;

    /// Child index within its immediate parent parameter.
    int childIndex;

    HAPI_ParmType type;

    /// Some parameter types require additional type information.
    ///     - File path parameters will indicate what file extensions they
    ///       expect in a space-separated list of wild-cards. This is set
    ///       in the Operator Type Properpties using the File Pattern
    ///       parameter property.
    ///       For example, for filtering by PNG and JPG only: "*.png *.jpg"
    ///     - Node path parameters will indicate what type of nodes they
    ///       expect in an all-caps "NETWORKTYPE/NODETYPE" pattern. This
    ///       is set in the Operator Type Properpties using the Op Filter
    ///       parameter property.
    HAPI_StringHandle typeInfoSH;

    /// For the majority of parameter types permission will not be applicable.
    /// For file path parameters these permissions will indicate how the
    /// asset plans to use the file: whether it will only read it, only write
    /// to it, or both. This is set in the Operator Type Properpties using
    /// the Browse Mode parameter property.
    HAPI_Permissions permissions;

    /// Tuple size. For scalar parameters this value is 1, but for vector
    /// parameters this value can be greater.  For example, a 3 vector would
    /// have a size of 3. For folders and folder lists, this value is the
    /// number of children they own.
    int size;

    /// Any ::HAPI_ParmType can be a choice list. If this is set to
    /// ::HAPI_CHOICELISTTYPE_NONE, than this parameter is NOT a choice list.
    /// Otherwise, the parameter is a choice list of the indicated type.
    /// See @ref HAPI_Parameters_ChoiceLists.
    HAPI_ChoiceListType choiceListType;

    /// Any ::HAPI_ParmType can be a choice list. If the parameter is a
    /// choice list, this tells you how many choices it currently has.
    /// Note that some menu parameters can have a dynamic number of choices
    /// so it is important that this count is re-checked after every cook.
    /// See @ref HAPI_Parameters_ChoiceLists.
    int choiceCount;

    /// Note that folders are not real parameters in Houdini so they do not
    /// have names. The folder names given here are generated from the name
    /// of the folderlist (or switcher) parameter which is a parameter. The
    /// folderlist parameter simply defines how many of the "next" parameters
    /// belong to the first folder, how many of the parameters after that
    /// belong to the next folder, and so on. This means that folder names
    /// can change just by reordering the folders around so don't rely on
    /// them too much. The only guarantee here is that the folder names will
    /// be unique among all other parameter names.
    HAPI_StringHandle nameSH;

    HAPI_StringHandle labelSH;

    /// If this parameter is a multiparm instance than the
    /// ::HAPI_ParmInfo::templateNameSH will be the hash-templated parm name,
    /// containing #'s for the parts of the name that use the instance number.
    /// Compared to the ::HAPI_ParmInfo::nameSH, the ::HAPI_ParmInfo::nameSH
    /// will be the ::HAPI_ParmInfo::templateNameSH but with the #'s
    /// replaced by the instance number. For regular parms, the
    /// ::HAPI_ParmInfo::templateNameSH is identical to the
    /// ::HAPI_ParmInfo::nameSH.
    HAPI_StringHandle templateNameSH;

    /// The help string for this parameter
    HAPI_StringHandle helpSH;

    /// Whether min/max exists for the parameter values.
    /// @{
    HAPI_Bool hasMin;
    HAPI_Bool hasMax;
    HAPI_Bool hasUIMin;
    HAPI_Bool hasUIMax;
    /// @}

    /// Parameter value range, shared between int and float parameters.
    /// @{
    float min;
    float max;
    float UIMin;
    float UIMax;
    /// @}

    /// Whether this parm should be hidden from the user entirely. This is
    /// mostly used to expose parameters as asset meta-data but not allow the
    /// user to directly modify them.
    HAPI_Bool invisible;

    /// Whether this parm should appear enabled or disabled.
    HAPI_Bool disabled;

    /// If true, it means this parameter doesn't actually exist on the node
    /// in Houdini but was added by Houdini Engine as a spare parameter.
    /// This is just for your information. The behaviour of this parameter
    /// is not any different than a non-spare parameter.
    HAPI_Bool spare;

    HAPI_Bool joinNext;  ///< Whether this parm should be on the same line as
                    ///< the next parm.
    HAPI_Bool labelNone; ///< Whether the label should be displayed.

    /// The index to use to look into the values array in order to retrieve
    /// the actual value(s) of this parameter.
    /// @{
    int intValuesIndex;
    int floatValuesIndex;
    int stringValuesIndex;
    int choiceIndex;
    /// @}

    /// See @ref HAPI_Parameters_MultiParms.
    /// @{
    HAPI_Bool isChildOfMultiParm;

    int instanceNum; ///< The index of the instance in the multiparm.
    int instanceLength; ///< The number of parms in a multiparm instance.
    int instanceCount; ///< The number of instances in a multiparm.

    /// First instance's ::HAPI_ParmInfo::instanceNum. Either 0 or 1.
    int instanceStartOffset;

    HAPI_RampType rampType;
    /// @}
};
HAPI_C_STRUCT_TYPEDEF( HAPI_ParmInfo )

struct HAPI_API HAPI_ParmChoiceInfo
{
    HAPI_ParmId parentParmId;
    HAPI_StringHandle labelSH;

    /// This evaluates to the value of the token associated with the label
    /// applies to string menus only.
    HAPI_StringHandle valueSH;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_ParmChoiceInfo )

// HANDLES ------------------------------------------------------------------

/// @struct HAPI_HandleInfo
///
/// Contains handle information such as the type of handle
/// (translate, rotate, scale, softxform ...etc) and the number of
/// parameters the current handle is bound to.
///
struct HAPI_API HAPI_HandleInfo
{
    HAPI_StringHandle nameSH;
    HAPI_StringHandle typeNameSH;

    int bindingsCount;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_HandleInfo )

/// @struct HAPI_HandleBindingInfo
///
/// Contains binding information that maps the handle parameter to
/// the asset parameter
///
struct HAPI_API HAPI_HandleBindingInfo
{
    HAPI_StringHandle handleParmNameSH;
    HAPI_StringHandle assetParmNameSH;

    HAPI_ParmId assetParmId;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_HandleBindingInfo )

// OBJECTS ------------------------------------------------------------------

struct HAPI_API HAPI_ObjectInfo
{
    HAPI_ObjectId id;

    HAPI_StringHandle nameSH;
    HAPI_StringHandle objectInstancePathSH;

    /// For incremental updates. Indicates whether the object's transform
    /// has changed. Refreshed only during an asset cook.
    HAPI_Bool hasTransformChanged;

    /// For incremental updates. Indicates whether any of the object's
    /// geometry nodes have changed. Refreshed only during an asset cook.
    HAPI_Bool haveGeosChanged;

    /// Whether the object is hidden and should not be shown. Some objects
    /// should be hidden but still brought into the host environment, for
    /// example those used only for instancing.
    /// See @ref HAPI_Instancing.
    HAPI_Bool isVisible;

    /// See @ref HAPI_Instancing.
    HAPI_Bool isInstancer;

    /// The number of geometries under this object. For those familiar with
    /// Houdini, this number will always include the one visible SOP and any
    /// SOPs that were exposed as "editable" or "templated".
    /// See @ref HAPI_ObjectsGeosParts_Geos.
    int geoCount;

    /// Use the node id to get the node's parameters.
    /// Using the HDK, you can also get the raw node C++ pointer for this
    /// object's internal node.
    /// See @ref HAPI_Nodes_Basics.
    HAPI_NodeId nodeId;

    /// If the object is an instancer, this variable gives the object id of
    /// the object that should be instanced.
    /// See @ref HAPI_Instancing.
    HAPI_ObjectId objectToInstanceId;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_ObjectInfo )

// GEOMETRY -----------------------------------------------------------------

struct HAPI_API HAPI_GeoInfo
{
    HAPI_GeoId id;
    HAPI_GeoType type;
    HAPI_StringHandle nameSH;

    /// Use the node id to get the node's parameters.
    /// Using the HDK, you can also get the raw node C++ pointer for this
    /// object's internal node.
    HAPI_NodeId nodeId;

    /// Whether the SOP node has been exposed by dragging it into the
    /// editable nodes section of the asset definition.
    HAPI_Bool isEditable;

    /// Has the templated flag turned on which means "expose as readonly".
    HAPI_Bool isTemplated;

    /// Final Result (Display SOP).
    HAPI_Bool isDisplayGeo;

    /// For incremental updates.
    HAPI_Bool hasGeoChanged;

    /// (deprecated) This variable is deprecated and should no longer be used.
    /// Materials are now seperate from parts. They are maintained at the
    /// asset level so you only need to check if the material itself has
    /// changed via ::HAPI_MaterialInfo::hasChanged instead of the material
    /// on the part.
    HAPI_Bool hasMaterialChanged;

    /// Groups.
    /// @{
    int pointGroupCount;
    int primitiveGroupCount;
    /// @}

    /// Total number of parts this geometry contains.
    /// See @ref HAPI_ObjectsGeosParts_Parts.
    int partCount;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_GeoInfo )

struct HAPI_API HAPI_GeoInputInfo
{
    HAPI_ObjectId objectId;
    HAPI_GeoId geoId;
    HAPI_NodeId objectNodeId;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_GeoInputInfo )

struct HAPI_API HAPI_PartInfo
{
    HAPI_PartId id;
    HAPI_StringHandle nameSH;
    HAPI_PartType type;

    int faceCount;
    int vertexCount;
    int pointCount; ///< Number of points. Note that this is NOT the number
                    ///< of "positions" as "points" may imply. If your
                    ///< geometry has 3 points then set this to 3 and not 3*3.

    int pointAttributeCount;
    int faceAttributeCount;
    int vertexAttributeCount;
    int detailAttributeCount;

    /// If this is true, don't display this part. Load its data but then
    /// instance it where the corresponding instancer part tells you to
    /// instance it.
    HAPI_Bool isInstanced;

    /// The number of parts that this instancer part is instancing.
    /// For example, if we're instancing a curve and a box, they would come
    /// accross as two parts, hence this count would be two.
    /// Call ::HAPI_GetInstancedPartIds() to get the list of ::HAPI_PartId's.
    int instancedPartCount;

    /// The number of instances that this instancer part is instancing.
    /// Using the same example as with ::HAPI_PartInfo::instancedPartCount,
    /// if I'm instancing the merge of a curve and a box 5 times, this count
    /// would be 5. To be clear, all instanced parts are instanced the same
    /// number of times and with the same transform for each instance.
    /// Call ::HAPI_GetInstancerPartTransforms() to get the transform of
    /// each instance.
    int instanceCount;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_PartInfo )

/// See @ref HAPI_Attributes.
struct HAPI_API HAPI_AttributeInfo
{
    HAPI_Bool exists;

    HAPI_AttributeOwner owner;
    HAPI_StorageType storage;

    /// When converting from the Houdini native GA geometry format to the
    /// GT geometry format HAPI uses, some attributes might change owners.
    /// For example, in Houdini GA curves can have points shared by
    /// vertices but the GT format only supports curve vertices
    /// (no points). This means that if you had point attributes on a curve
    /// in Houdini, when it comes out of HAPI those point attributes will now
    /// be vertex attributes. In this case, the ::HAPI_AttributeInfo::owner
    /// will be set to ::HAPI_ATTROWNER_VERTEX but the
    /// ::HAPI_AttributeInfo::originalOwner will be ::HAPI_ATTROWNER_POINT.
    HAPI_AttributeOwner originalOwner;

    /// Number of attributes. This count will match the number of values
    /// given the owner. For example, if the owner is ::HAPI_ATTROWNER_VERTEX
    /// this count will be the same as the ::HAPI_PartInfo::vertexCount.
    /// To be clear, this is not the number of values in the attribute, rather
    /// it is the number of attributes. If your geometry has three 3D points
    /// then this count will be 3 (not 3*3) while the
    /// ::HAPI_AttributeInfo::tupleSize will be 3.
    int count;

    /// Number of values per attribute.
    /// Note that this is NOT the memory size of the attribute. It is the
    /// number of values per attributes. Multiplying this by the
    /// size of the ::HAPI_AttributeInfo::storage will give you the memory
    /// size per attribute.
    int tupleSize;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_AttributeInfo )

// MATERIALS ----------------------------------------------------------------

struct HAPI_API HAPI_MaterialInfo
{
    HAPI_MaterialId id;
    HAPI_AssetId assetId;

    /// This is the HAPI node id for the SHOP node this material is attached
    /// to. Use it to get access to the parameters (which contain the
    /// texture paths).
    /// IMPORTANT: When the ::HAPI_MaterialInfo::hasChanged is true this
    /// @p nodeId could have changed. Do not assume ::HAPI_MaterialInfo::nodeId
    /// will never change for a specific material.
    HAPI_NodeId nodeId;

    HAPI_Bool exists;

    HAPI_Bool hasChanged;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_MaterialInfo )

struct HAPI_API HAPI_ImageFileFormat
{
    HAPI_StringHandle nameSH;
    HAPI_StringHandle descriptionSH;
    HAPI_StringHandle defaultExtensionSH;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_ImageFileFormat )

struct HAPI_API HAPI_ImageInfo
{
    /// Unlike the other members of this struct changing imageFileFormatNameSH
    /// and giving this struct back to HAPI_SetImageInfo() nothing will happen.
    /// Use this member variable to derive which image file format will be used
    /// by the HAPI_ExtractImageTo...() functions if called with
    /// image_file_format_name set to NULL. This way, you can decide whether
    /// to ask for a file format conversion (slower) or not (faster).
    HAPI_StringHandle imageFileFormatNameSH; // Readonly

    int xRes;
    int yRes;

    HAPI_ImageDataFormat dataFormat;

    HAPI_Bool interleaved; ///< ex: true = RGBRGBRGB, false = RRRGGGBBB
    HAPI_ImagePacking packing;

    /// Adjust the gamma of the image. For anything less than
    /// ::HAPI_IMAGE_DATA_INT16, you probably want to leave this as 2.2.
    double gamma;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_ImageInfo )

// ANIMATION ----------------------------------------------------------------

struct HAPI_API HAPI_Keyframe
{
    float time;
    float value;
    float inTangent;
    float outTangent;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_Keyframe )

// VOLUMES ------------------------------------------------------------------

/// @struct HAPI_VolumeInfo
///
/// This represents a volume primitive but does not contain the actual voxel
/// values, which can be retrieved on a per-tile basis.
///
/// See @ref HAPI_Volumes.
///
struct HAPI_API HAPI_VolumeInfo
{
    HAPI_StringHandle nameSH;

    HAPI_VolumeType type;

    /// Each voxel is identified with an index. The indices will range
    /// between:
    /// [ ( minX, minY, minZ ), ( minX+xLength, minY+yLength, minZ+zLength ) )
    /// @{
    int xLength;
    int yLength;
    int zLength;
    int minX;
    int minY;
    int minZ;
    /// @}

    /// Number of values per voxel.
    /// The tuple size field is 1 for scalars and 3 for vector data.
    int tupleSize;

    /// Can be either ::HAPI_STORAGETYPE_INT or ::HAPI_STORAGETYPE_FLOAT.
    HAPI_StorageType storage;

    /// The dimensions of each tile.
    /// This can be 8 or 16, denoting an 8x8x8 or 16x16x16 tiles.
    int tileSize;

    /// The transform of the volume with respect to the lengths.
    /// The volume may be positioned anywhere in space.
    HAPI_Transform transform;

    /// Denotes special situations where the volume tiles are not perfect
    /// cubes, but are tapered instead.
    HAPI_Bool hasTaper;

    /// If there is taper involved, denotes the amount of taper involved.
    /// @{
    float xTaper;
    float yTaper;
    /// @}
};
HAPI_C_STRUCT_TYPEDEF( HAPI_VolumeInfo )

/// @struct HAPI_VolumeTileInfo
///
/// A HAPI_VolumeTileInfo represents an cube subarray of the volume.
/// The size of each dimension is HAPI_VoluemInfo::tileSize
/// bbox [(minX, minY, minZ), (minX+tileSize, minY+tileSize, minZ+tileSize))
///
struct HAPI_API HAPI_VolumeTileInfo
{
    int minX;
    int minY;
    int minZ;
    HAPI_Bool isValid;
};
HAPI_C_STRUCT_TYPEDEF( HAPI_VolumeTileInfo )

// CURVES -------------------------------------------------------------------

/// @struct HAPI_CurveInfo
///
/// This represents the meta-data associated with a curve mesh (a number
/// of curves of the same type).
struct HAPI_API HAPI_CurveInfo
{
    HAPI_CurveType curveType;
    int curveCount; ///< The number of curves contained in this curve mesh.
    int vertexCount; ///< The number of control vertices (cvs) for all curves.
    int knotCount; ///< The number of knots for all curves.

    HAPI_Bool isPeriodic;
        ///< Whether the curves in this curve mesh are periodic.
    HAPI_Bool isRational;
        ///< Whether the curves in this curve mesh are rational.
    int order; ///< Order of 1 is invalid. 0 means there is a varying order.

    HAPI_Bool hasKnots; ///< Whether the curve has knots.
};
HAPI_C_STRUCT_TYPEDEF( HAPI_CurveInfo )

#endif // __HAPI_COMMON_h__
