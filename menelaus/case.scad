// -*- mode: c -*-
/* All distances are in mm. */

$fn = 50;
angle = 10;
hole_radius = 1.5;
washer_radius = 3 * hole_radius;
spacing = 19;
hand_distance = spacing * 2;
switch_size = 13.97;
rows = 4;
cols = 5;
row_offset = 4;

module rz(angle, center=undef) translate(center) rotate(angle) translate(-center) children();
module mirrored() { children(); mirror([1, 0, 0]) children(); }
module key(pos, size) translate(pos) square([size, size], center = true);
module hole(pos, size) translate(pos) circle(size);
module add_hand_distance() translate([0.5 * hand_distance, 0]) children();
module rotate_half() add_hand_distance() rz(angle, [hand_distance, spacing]) children();
module plate_bottom() difference() { hull() holes(washer_radius); holes(hole_radius); }
module plate_top() difference() { plate_bottom(); keys(switch_size); }
module keys(size) mirrored() items(size);
module teensy() translate([0, 5]) square([15, 30], center = true);

module pcb_hole(pos, mirrored) translate(pos) mirror([mirrored ? 1 : 0, 0, 0]) union() {
    circle(2);
    translate([-3.81, 2.54]) circle(1.5);
    translate([2.54, 5.08]) circle(1.5);
}

module items(size, pcb_holes, mirrored) rotate_half() {
  for (c =[0 : cols - 1]) for(r=[0 : rows - 1]) {
    offset = c == 2 && r != 0 ? row_offset : c == rows ? -row_offset : 0;
    if (!(r == 0 && (c == 3 || c == 4))) {
        if (pcb_holes) {
            pcb_hole([c * spacing, r * spacing + offset], mirrored);
        } else {
            key([c * spacing, r * spacing + offset], size);
        }
    }
  }
}


module pcb_holes() {
    items(0, true, false);
    mirror([1, 0, 0]) items(0, true, true);
}

module holes(radius) mirrored() {
  offset1 = spacing * 0.5 + 3;
  offset2 = switch_size * 0.5;
  top_corner = [(cols - 1) * spacing + offset2, (rows - 1) * spacing + offset1 - row_offset];
  rotate_half() {
    hole(top_corner, radius);
    hole([(cols - 1) * spacing + offset2, spacing - offset1 - row_offset], radius);
    hole([2 * spacing + offset1, -offset2], radius);
    hole([-offset1, -offset2], radius);
  }
  translate([((cols - 2) * -spacing - offset2) / cos(angle), 0]) rotate_half() hole(top_corner, radius);
}

module plate_middle() difference() {
  union() {
    difference() {
      plate_bottom();
      hull() keys(16);
    }
    holes(washer_radius);
    translate([0, 64]) polygon([[-10, -5],[10,-5],[20,7],[-20,7]]);
  }
  holes(hole_radius);
  translate([0, 73]) square([9, 30], center = true);
}

module pcb() difference() {
  plate_bottom();
  pcb_holes();
  //keys(14);
  hull() {
      translate([-10, -8]) circle(3);
      translate([10, -8]) circle(3);
      translate([0, 43]) circle(4);
  }
  translate([0, 80]) square([9, 30], center = true);
  translate([0, 65]) circle(4.5);
}

module pcb1() difference() {
  mirrored() difference() {
    union() {
      hull() union() {
        translate([23, 70]) circle(3);
        items(16);
      }
      translate([0, -17]) square([17, 7]);
      translate([0, 54]) square([10, 8]);
    }
    holes(hole_radius);
  }
  pcb_holes();
  //keys(switch_size);
}

module case_top() difference() union() {
  linear_extrude(height = 5) plate_middle();
  linear_extrude(height = 1.5) pcb1();
  translate([0, 0, 3.5]) linear_extrude(height = 1.5) translate([0, 74]) square([10, 6], center = true);
}

module case_bottom() union() {
  linear_extrude(height = 4) plate_middle();
  linear_extrude(height = 1.5) translate([0, 68]) square([10, 18], center = true);
}

//plate_top();
//translate([0, 120]) plate_bottom();
//translate([230, 120]) plate_middle();
//translate([230, 120]) keys(switch_size, true);
//translate([0, 120]) case_top();
translate([0, 0]) pcb();
//translate([0, 0]) case_bottom();
//translate([0, 0]) teensy();
