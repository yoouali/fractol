# fractol
Fractol is a graphic program that render amazing fractals ,developed for my learning course at 42 school for the exploration of Fractals.

* Zoom and unzoom
* Change the number of iterations
* Move the current fractal
* Change the display color and gradient
* Navigate between the fractals
* Edit the shape of the fractal with the position of the mouse (only available with the fractal Julia,feigenbaum-point ,burning_julia)

![Preview](images/fractal.png?raw=true)


## Install & launch
```bash
git clone https://github.com/yoouali/fractol ~/fractol
cd ~/fractol
brew install zlib
make
./fractol mandelbrot
```
You have to launch the program with a parameter. This is the name of the fractal you would like to open at the execution of the program. This parameter as to be the name of a valid fractal (Julia, Mandelbrot, Burning-julia, Feigenbaum, Teardrop or Tricorn).<br />

## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the map</td>
<td valign="top" align="center"><kbd>&nbsp;c&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the up</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the down</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the left</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the right</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
  <td valign="top" height="30px">coloration methode changing</td>
<td valign="top" align="center"><kbd>&nbsp;m&nbsp;</kdb></td>
</tr>
<td valign="top" height="30px">Color changing</td>
<td valign="top" align="center"><kbd>&nbsp;< >&nbsp;</kdb></td>
</tr>
<tr>
<td valign="top" height="30px">Freez Julia</td>
<td valign="top" align="center"><kbd>&nbsp;f&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Speed mode </td>
<td valign="top" align="center"><kbd>&nbsp;s&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Reset</td>
<td valign="top" align="center"><kbd>&nbsp;r&nbsp;</kbd></td>
</tr>
</tbody>
</table>

## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<td valign="top" height="30px">Zoom</td>
<td valign="top" align="center"><kbd>&nbsp;scroll up&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Unzoom</td>
<td valign="top" align="center"><kbd>&nbsp;scroll down&nbsp;</kbd></td>
</tr>
</tbody>
</table>

Example :
# Mandelbrot:
![Preview](images/mandlb.png?raw=true)

# Julia:
![Preview](images/julia.png?raw=true)

# Tricorn:
![Preview](images/tricorn.png?raw=true)

# Burning ship:
![Preview](images/burning_ship.png?raw=true)

# Burning julia:
![Preview](images/burning_julia.png?raw=true)

# Feigenbaum point:
![Preview](images/feigenbaum_point.png?raw=true)

#  Reality point
![Preview](images/reality_point.png?raw=true)

#  Imagine point
![Preview](images/imagine_point.png?raw=true)

#  Teardrop
![Preview](images/teardrop.png?raw=true)