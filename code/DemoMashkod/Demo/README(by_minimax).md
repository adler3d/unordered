# DemoMashkod Demo - Virtual Machine and Game Engine

> Main demonstration application of the DemoMashkod project, implementing a complete virtual machine with custom assembly language, graphics engine, and physics simulation.

---

## 🎯 Overview

This directory contains the main executable demo of the DemoMashkod project - a sophisticated virtual machine that demonstrates:
- **Custom Assembly Language** with register-based instruction set
- **QapLite Graphics Engine** for real-time rendering
- **Physics Simulation** with rigid body dynamics
- **Code Generation** from C++-like syntax through multiple compilation stages

---

## 📁 File Structure & Architecture

### **Core Engine Files**

#### `QapLite.h` - **Graphics & Input Framework**
- **Purpose**: Unified graphics and input handling system
- **Features**: 
  - Real-time 2D rendering pipeline
  - Input handling (keyboard, mouse)
  - Window management and game loop
  - Texture and sprite management
  - Immediate-mode rendering interface
- **Used by**: All visual components and UI rendering

#### `TQapGameV2.inl` - **Game Engine Core**
- **Purpose**: High-level game framework built on QapLite
- **Components**:
  - Scene management system
  - Entity-component architecture
  - Animation and timing systems
  - Event handling and user interaction
- **Architecture**: Component-based design with scene graphs

### **Virtual Machine Core**

#### `main.cpp` - **Main VM Implementation** (1396 lines)
**Primary execution file containing the complete virtual machine:**

- **VM Architecture**:
  - Register-based CPU with 13+ general-purpose registers
  - Custom instruction set with 50+ commands
  - Memory management with stack and heap
  - Command execution pipeline with debug support

- **Key Classes**:
  - `t_cmd`: Command structure with id, dest, a, b parameters
  - `t_machine`: Main VM class with register file and execution logic
  - Register set: eax, ebx, ecx, edx, ebp, esp, edi, esi, eip, err, cmd_counter, debug_depth

- **Instruction Set**:
  ```cpp
  // Arithmetic operations
  CMD_LIKE_ADD(CASE_CMD,ADD)
  CMD_LIKE_ADD(CASE_CMD,SUB)
  CMD_LIKE_ADD(CASE_CMD,MUL)
  CMD_LIKE_ADD(CASE_CMD,DIV)
  
  // Memory operations  
  CMD_LIKE_MOV(CASE_CMD,MOV)
  
  // Control flow
  // Jump, call, ret operations
  ```

- **Compilation Pipeline**:
  1. C++-like syntax parsing
  2. First stage: Conversion to AsmCppLike intermediate representation
  3. Second stage: Translation to Mashkod bytecode
  4. Execution on virtual machine

### **System & Utility Files**

#### `qap_sys.inl` - **Data Serialization System**
**Advanced data persistence and reflection system:**

- **Core Components**:
  - `Sys$$<TYPE>`: Template-based serialization system
  - `ProxySys$$`: Runtime type information for custom serialization
  - `TDataIO`: Binary data input/output system

- **Features**:
  - Automatic serialization for custom types
  - Version-aware data storage
  - Type-safe data loading/saving
  - Support for complex nested data structures
  - Special handling for graphics types (QapColor, vec2i, vec2f, vec2d)

- **Usage Example**:
  ```cpp
  // Automatic serialization
  QapSave(IO, myObject);
  QapLoad(IO, myObject);
  
  // String-based serialization
  string data = QapSaveToStr(myObject);
  QapLoadFromStr(myObject, data);
  ```

#### `defprovar.inl` - **Property System Generator**
**Macro-based property and reflection system:**

- **Core Functionality**:
  - Automatic generation of property declarations
  - Reset and assignment operations
  - Serialization proxy generation
  - Move semantics support

- **Usage Pattern**:
  ```cpp
  struct MyClass{
    #define DEF_PRO_CLASSNAME()MyClass
    #define DEF_PRO_VARIABLE(ADD)\
    ADD(int,value,0)\
    ADD(string,name,"")\
    //===
    #include "defprovar.inl"
    //===
  };
  ```

- **Generated Features**:
  - Automatic constructors and destructors
  - Reset to default values
  - Move assignment operators
  - Serialization/deserialization methods

### **Geometry & Rendering**

#### `t_geom.inl` - **Geometry Generation System**
**2D geometry generation and manipulation library:**

- **Core Structure**: `t_geom`
  - `vector<vec2d> VA`: Vertex array for positions
  - `vector<int> IA`: Index array for triangle connectivity

- **Primitive Generation**:
  - **Quad Generation**: `GenGeomQuad()` - Creates 2D rectangles
  - **Solid Circle**: `GenGeomCircleSolid()` - Filled circle meshes
  - **Ring/Annulus**: `GenGeomCircleEx()` - Hollow circular structures
  - **Line Lists**: `GenGeomLineList()` - Polyline generation

- **Mesh Operations**:
  - Triangle addition: `AddTris(a,b,c)`
  - Vertex management: `AddVertex()`, `AddVertexAndRetVID()`
  - Geometry combination: `add()`, `add_with_offset()`

- **Example Usage**:
  ```cpp
  // Generate rectangle at (100,100) with size 50x30
  t_geom quad = GenGeomQuad(100, 100, 50, 30);
  
  // Generate circle with radius 25, 32 segments
  t_geom circle = GenGeomCircleSolid(25, 32, 0);
  ```

#### `t_quad.inl` - **Quad Tree Spatial Partitioning**
**Efficient spatial data structure for collision detection and rendering optimization:**

- **Purpose**: Hierarchical space partitioning for fast object queries
- **Applications**:
  - Collision detection optimization
  - View frustum culling
  - Spatial indexing for large object sets
- **Implementation**: Binary space partitioning with recursive subdivision

### **Assembly Integration**

#### `asm_header.inl` - **Assembly Register Mapping**
**Register and memory model definitions for VM:**

```cpp
// Register declarations
t_reg reg(ctti); 
t_mem mem(ctti); 
t_raw_pro raw(ctti);
t_ptr ptr(ctti);

// Register name macros
#define F(NAME)auto&NAME=reg[::NAME];
DEF_PRO_REGISTERS(F)
#undef F
```

#### `asmogovno.inl` - **Assembly Code Templates**
**Preprocessor macros for assembly instruction generation:**

- **Command Generation Macros**:
  - `CMD_LIKE_ADD`: Generates arithmetic instruction variants
  - `CMD_LIKE_MOV`: Generates move instruction variants  
  - `CMD_ONEPARAM_IS_OUT`: Single-parameter instruction templates
- **Memory Addressing**: Support for register, memory, and immediate addressing modes

### **Camera & Input Systems**

#### `cam_code.inl` - **Camera Control System**
**2D camera management and transformation system:**

- **Features**:
  - Camera position and rotation tracking
  - View transformation matrices
  - Zoom and pan capabilities
  - Screen-to-world coordinate conversion

### **Development & Build Tools**

#### `get_cpu_speed.cpp` - **Performance Measurement**
**CPU performance and timing utilities:**

- **Purpose**: High-resolution timing for performance profiling
- **Usage**: Measuring VM execution speed and optimization benchmarks

#### `pro_app_build_impl.inl` - **Application Builder**
**Application construction and initialization framework:**

- **Purpose**: Standard application startup and lifecycle management
- **Components**: 
  - Application initialization
  - Resource loading
  - Main game loop
  - Cleanup and shutdown

#### `pro_crap_ctor_impl.inl` - **Object Construction System**
**Advanced object construction and memory management:**

- **Features**:
  - RAII (Resource Acquisition Is Initialization) patterns
  - Memory pool management
  - Object lifecycle tracking
  - Debug memory validation

#### `special_cd_func.inl` - **Specialized Functions**
**Domain-specific utility functions:**

- **Purpose**: Specialized algorithms and computational geometry
- **Applications**: Custom mathematical operations, data transformations

---

## 🏗️ Build System

### **Visual Studio Integration**
- **Project File**: `Demo.vcxproj` (Visual Studio 2013+)
- **Platform**: Win32
- **Configurations**: Debug/Release
- **Preprocessor Definitions**:
  - Debug: `WIN32`, `_DEBUG`, `_WINDOWS`
  - Release: `QAP_DEBUG`, `WIN32`, `NDEBUG`, `_WINDOWS`

### **Compilation Dependencies**
```
# Core Headers
QapLite.h
TQapGameV2.inl

# System Dependencies  
qap_sys.inl
defprovar.inl

# Graphics Dependencies
t_geom.inl
t_quad.inl

# VM Dependencies
asm_header.inl
asmogovno.inl
cam_code.inl
```

---

## 🎮 Execution Flow

### **Application Startup**
1. **Initialization**: QapLite framework setup
2. **VM Creation**: Virtual machine instantiation with registers
3. **Graphics Setup**: Rendering pipeline initialization
4. **Scene Loading**: Game scene and assets preparation

### **VM Execution Cycle**
1. **Fetch**: Load next command from program memory
2. **Decode**: Parse instruction parameters and addressing modes
3. **Execute**: Perform operation (arithmetic, memory, control flow)
4. **Store**: Write results back to registers/memory
5. **Update**: Advance program counter and debug state

### **Graphics Rendering**
1. **Clear**: Frame buffer and depth buffer
2. **Camera**: Apply view transformations
3. **Draw**: Render geometry and sprites using QapLite
4. **UI**: Overlay interface and debugging information
5. **Present**: Swap buffers and handle input

---

## 🔧 Key Technical Concepts

### **Two-Stage Compilation**
```
High-Level (C++-like) 
    ↓ [V2/Sgon Parser]
AsmCppLike (Intermediate)
    ↓ [AsmCppLike2Mashkod]  
Mashkod Bytecode
    ↓ [VM Interpreter]
Execution
```

### **Register-Based Architecture**
- 13 general-purpose registers
- Support for memory, immediate, and register addressing
- Automatic register allocation and spill code generation
- Debug state tracking and error handling

### **Component-Based Design**
- Modular engine architecture
- Reusable components across projects
- Event-driven communication system
- Resource management and lifecycle tracking

---

## 📊 Performance Characteristics

- **Instruction Execution**: Variable timing based on operation complexity
- **Memory Usage**: Stack-based allocation with heap fallback
- **Rendering**: Immediate-mode with batch processing
- **Physics**: Real-time simulation at 60+ FPS for simple scenes

---

## 🎓 Educational Value

This demo serves as a comprehensive example of:

1. **Virtual Machine Design**: Complete CPU emulation with custom instruction set
2. **Graphics Programming**: Real-time 2D rendering with modern techniques
3. **Game Engine Architecture**: Modular, component-based design patterns
4. **System Programming**: Memory management, serialization, reflection
5. **Compiler Theory**: Multi-stage compilation and intermediate representations

The project demonstrates how complex software systems can be built from fundamental principles, making it an excellent reference for understanding game engine internals and virtual machine implementation.

---

*Part of the DemoMashkod ecosystem - showcasing custom language design and virtual machine construction from first principles.*
