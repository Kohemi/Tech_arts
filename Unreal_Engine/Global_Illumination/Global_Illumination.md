Understand Lightmass

## Baking checklist

* Mesh actors mobility should be set to static
* Lights mobility can be set to static or stationary
* Meshes require non-overlapping UVs
* Lightmap UVs can be auto-generated in UE4 based on existing UVs
* Set proper resolution per object 



UE4 can create UV map of static mesh automatically 

Process 

![image-20200302144939781](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200302144939781.png)

## Intro to Lightmass

* Stand alone application that handles light rendering, baking to lightmaps and integrating into materials
* Raytracer supporting most GI features
* Supports distributed rendering over a network



## Visualizing lightmaps

* Switch to lighting mode
* Turn off post-process
  * Auto Exposure -Causes exposure Changes
  * Bloom - Overly bright screen
  * Screen Space Ambient Occlusion(AO) - Difficult to tell if results are from the light bake or from AO



## Improving the Quality of the LightMass

### Lightmass setup

* Importance Volume
  * It does not calculate all over the world light 
  * Just focus on the Sector in volume 

* Portals
  * Lights throughout this Portals can be calculated more better and quickly 
* Quality Settings
* World Settings
  * Indirect Lighting Quality
  * Num Indirect Lighting Bounce
  * Static Lighting Level Scale - <u>If the quality of the shadow of mesh isn't enough, to Improve the quality of shadows between Mesh and contact shadows, you have to turn down this parameter !</u>
  * If you do not have enough quality of shadow, you get a noise. So you do not want this result, have to increase Indirect Lighting Quality!
  * ![image-20200302155840048](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200302155840048.png)
  * 
* INI Settings
* Meshes as Lights
  * Lightmass supports textured objects as light sources
  * Use Emisssive for static lighting in detail panel

<u>After Lightmass finishing calculating, it effect lighting as baking lightmap UVs of Mesh</u> 

####  Light propagation Volume(LPV) - Dynamic Global Illumination

* Positives
  * Run-time GI solution
  * Handles dynamic objects
  * No need for extra Uvs
* Negatives
  * More expensive
  * Highly approximated

How to run

```UE4
r.LightPropagationVolume = <int>
```



And



1. We need to change directional lights's mobility from "Static" to "Movable"
2. In detail panel, Check Dynamic Indirect Lighting 



