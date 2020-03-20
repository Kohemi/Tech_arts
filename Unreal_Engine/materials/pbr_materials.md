# PBR Materials

## Organizing Material Instance

### Material Instance

### Setting Up Groups and Parameter List Priorities 

 Material Expression -> Group

You can set up Material Expression Scalar Parameter's limit in Detail Tap 

### Dynamic Material Instances

Constant Material Instance 

* A great way to weak Materials without needing to recompile the Material after every change

Dynamic Material Instance

* allows us to tweak those Constant Material instances at runtime where the viewer can see the changes based upon whatever interactive events we choose 

Event Dispatchers 

* We can call it from the level Blueprint 

## Material parameters collection

## Material Functions 

* Material Functions are custom-built, reusable sinppets of Material Graphs. 
* These can be added to other Materials across multiple projects. 
* Making changes to a Material function means those changes will automatically propagate to all Material using the custom code. 

### Procedure

1.  Make a Material Functions at Contents Browser

2.  You can check out Output result on event Graphs 

3. Function input allows us to control the tiling of our UV Coordinates. 

   * Please Check!! Function input have 3vector but UV is only 2vector. so you can change the type of value. this can be possible at input type on detail panel!!

**Custom Rotator**

* This is another Material Function built by Unreal 
* We can embed other Material Functions inside of each other 
* This allows us to control the rotation of our UV Coordinates, as well as to control the center point of rotation 


