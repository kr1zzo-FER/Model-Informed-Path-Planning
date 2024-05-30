"""
@file: curve_factory.py
@breif: Facotry class for curve generation.
@author: Winter
@update: 2023.7.25
"""
from curve_generation.dubins_curve import Dubins
from curve_generation.bezier_curve import Bezier
from curve_generation.polynomial_curve import Polynomial
from curve_generation.reeds_shepp import ReedsShepp


class CurveFactory(object):
    def __init__(self) -> None:
        pass

    def __call__(self, curve_name, **config):
        if curve_name == "dubins":
            return Dubins(**config)
        elif curve_name == "bezier":
            return Bezier(**config)
        elif curve_name == "polynomial":
            return Polynomial(**config)
        elif curve_name == "reeds_shepp":
            return ReedsShepp(**config)
        """
        elif curve_name == "cubic_spline":
            return CubicSpline(**config)
        elif curve_name == "bspline":
            return BSpline(**config)
        elif curve_name == "fem_pos_smoother":
            return FemPosSmoother(**config)
        
        else:
            raise ValueError("The `curve_name` must be set correctly.")
        """