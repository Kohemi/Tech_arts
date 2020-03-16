# Material Essential Concepts

## 1. Textures

How do we get Normal map, Diffuse, Metallic, Roughness!!

### 1-1. Texture sizes

* 2^n X 2^n style
* 2^x X 2^y, Combination is Ok
* Textures will import as any size but will not have mipmaps 
* mipmaps are a smaller version of textures 

### 1-2. Texture formats

* TGA is commonly uncompressed 
* TGA, PSD is better. 

### 1-3. Importing Textures

### 1-4. Compression

* DXTC or BC means Compressed
* B8G8R8A8 or parts of it G8 means uncompressed
* Texture is compressed when it is imported

##  2. PBR Materials

### 2-1. What is PBR

* Physically based Rendering
* Approximating materials interaction with lighting through the Authoring of :
  * Metallic
  * Specular 
  * Roughness
* Used for nearly everything 
* Unified Shading 

### 2-2. PBR material values

### 2-3. Expanding on PBR materials

About Metallic

* Metallic property is based on a Boolean basis.
* treat it as if there is no Metallic, it is black. Everything that is white is Metallic 
* Don't try use in between values!! Just use 0 or 1 Boolean!
* 1 is white, 0 is black

About Roughness

* White means less reflection. 

## 3. Material Expressions

TextureCoordinate

* It has a value of Utilling and Vtilling. This value is essentially the scale of texture. 

Panner 

* It effects a moving of texture. 

Linear Interpolate(Lerp)

* It blends A and B together, based on C(Alpha)

### 3-2. Connecting Material Expressions 

[Example. how to make a material of ground water](https://cdnapisec.kaltura.com/html5/html5lib/v2.81.2/mwEmbedFrame.php/p/2501632/uiconf_id/44526772/entry_id/1_22yblb14?wid=_2501632&iframeembed=true&playerId=kaltura_player_1554750068&entry_id=1_22yblb14) 

### 3-3. Working with Material Inputs

World position offset 

* Just use this only for anything that doesn't need any collision 

###  

