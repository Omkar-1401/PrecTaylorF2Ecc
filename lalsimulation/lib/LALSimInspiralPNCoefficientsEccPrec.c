/*
*  Copyright (C) 2026 Omkar Sridhar and Soham Bhattacharyya
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with with program; see the file COPYING. If not, write to the
*  Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
*  MA  02110-1301  USA
*/

#include <lal/LALConstants.h>
#include <lal/LALAtomicDatatypes.h>
#include <math.h>

#ifdef __GNUC__
#define UNUSED __attribute__ ((unused))
#else
#define UNUSED
#endif

/**
 * Computes the PN Coefficients for using in the PN energy equation.
 *
 * Terms given in equation 3.1 of: Alessandra Buonanno, Bala R Iyer, Evan
 * Ochsner, Yi Pan, and B S Sathyaprakash, "Comparison of post-Newtonian
 * templates for compact binary inspiral signals in gravitational-wave
 * detectors", Phys. Rev. D 80, 084043 (2009), arXiv:0907.0700v1
 * For the spin terms a good reference are (3.15) and (3.16) of 1303.7412
 *
 * In the latest version coefficients of the terms n.S and L.S are reported
 * "Averaged" spin coefficients refer to the ones obtained by orbital averaging,
 * i.e. by using
 * n_i n_j = 1/2 (\f$\delta_{ij} - \hat LN_i \hat LN_j\f$)
 * However such orbital averaging at 2PN would introduce corrections
 * at 3PN, as LNh is not constant.
 */

/*
 * Spin-squared corrections to TF2 phasing
 * Compute 2.0PN SS, QM, and self-spin
 * See Eq. (6.24) in arXiv:0810.5336
 * 9b,c,d in arXiv:astro-ph/0504538
 * Note that these terms are understood to multiply
 * dimensionless spin magnitudes \chi_i=S_i/m_i^2
 * differently from the convention adopted for SpinTaylorTX
 * whose spinning coefficients multiply \chi_LAL=S_i/M^2
 * where M=m_1+m_2.
 * See also https://dcc.ligo.org/T1800298
 */

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNS1S2PrecCoeff(
        REAL8 eta
    )
{
  return  -523.55/9.92*eta;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNS1S2OPrecCoeff(
        REAL8 eta
    )
{
  return  -456.05/9.92*eta;
}


static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecCoeff(
        REAL8 mByM
    )
{
  return -147.285/1.984*mByM*mByM;
}



static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecCoeff(
        REAL8 mByM
    )
{
  return 46.845/1.984*mByM*mByM;
}


static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_3PNSOEccCoeff(
        REAL8 mByM,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (4.3*mByM*(3.4401 + 2.6779*mByM))/2.11950;
                break;
        case 3:
                phase = - (mByM*(10.2 + 5.5*mByM))/5.4;
                break;
        }
        return  phase;
}


static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(
        REAL8 mByM,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (-7.31*mByM*(-12.42043275 - 12.73890388*mByM - 2.17526764*mByM*mByM + 4.15391200*mByM*mByM*mByM))/1.136594592;
                break;
        case 2:
                phase = (4.3*mByM*(9.7458033 - 11.3891009*mByM + 4.2042952*mByM*mByM + 14.7712964*mByM*mByM*mByM))/2.136456;
                break;
        case 3:
                phase = (7.31*mByM*(-4.1731566 - 9.5824403*mByM + 3.3785668*mByM*mByM + 3.9536420*mByM*mByM*mByM))/4.426736832;
                break;
        case 5:
                phase = -((mByM*(59.0055 + 6.3902*mByM + 27.9356*mByM*mByM + 34.5760*mByM*mByM*mByM))/3.8880);
                break;
        }
        return  phase;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_6PNSOEccCoeff(
        REAL8 mByM,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = LAL_PI*(-7.31*mByM*(54.449547 + 37.080578*mByM))/4.883328;
                break;
        case 3:
                phase = LAL_PI*(4.3*mByM*(19.656399 + 13.701538*mByM))/1.52604;
                break;
        case 6:
                phase = -LAL_PI*((mByM*(8.1717 + 7.5326*mByM))/1.5552);
                break;
        }
        return  phase;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNS1S2PrecEccCoeff(
        REAL8 eta,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (-9.62271587*eta)/1.23349248;
                break;
        case 4:
                phase = (5.005*eta)/2.304;
                break;
        }
        return  phase;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNS1S2OPrecEccCoeff(
        REAL8 eta,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (-7.54689517*eta)/1.23349248;
                break;
        case 4:
                phase = (2.915*eta)/2.304;
                break;
        }
        return  phase;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecEccCoeff(
        REAL8 mByM,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (-26.57441581*mByM*mByM)/2.46698496;
                break;
        case 4:
                phase = (12.707*mByM*mByM)/4.608;
                break;
        }
        return  phase;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecEccCoeff(
        REAL8 mByM,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (7.4238167*mByM*mByM)/2.2427136;
                break;
        case 4:
                phase = (-3.539*mByM*mByM)/4.608;
                break;
        }
        return  phase;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNS1S2PrecIndCircCoeff(
        REAL8 eta
    )
{
        return (0.11775*eta)/3.62576;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNS1S2OPrecIndCircCoeff(
        REAL8 eta
    )
{
        return (-0.11775*eta)/3.62576;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecIndCircCoeff(
        REAL8 mByM
    )
{
        return (-0.11775*mByM*mByM)/7.25152;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecIndCircCoeff(
        REAL8 mByM
    )
{
        return (0.11775*mByM*mByM)/7.25152;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_6PNS1S2OEccCoeff(
        REAL8 eta,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (-7.31*eta*(40.20569403 + 28.73178980*eta))/4.10199552;
                break;
        case 2:
                phase = (3.974447*eta*(-28.33 + 55.16*eta))/2.87814912;
                break;
        case 3:
                phase = (-4.3*eta*(11.641317 + 2.945690*eta))/1.14453;
                break;
        case 4:
                phase = (4.0205*eta*(4.09133 + 7.18844*eta))/1.311625728;
                break;
        case 6:
                phase = -((eta*(-62.21289 + 41.53580*eta))/1.86624);
                break;                
        }
        return  phase;
}

static REAL8 UNUSED
XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(
        REAL8 mByM,
        INT4 v0_order
    )
{
        REAL8 phase = 0.0;
        switch (v0_order) {
        case 0: 
                phase = (7.31*mByM*mByM*(-29.99478969 - 50.20858668*mByM + 43.51928140*mByM*mByM))/8.20399104;
                break;
        case 2:
                phase = -((3.8350453*mByM*mByM*(28.33 - 55.16*mByM + 55.16*mByM*mByM))/5.180668416);
                break;
        case 3:
                phase = -((4.3*mByM*mByM*(3.508902 + 4.623513*mByM + 1.472845*mByM*mByM))/1.14453);
                break;
        case 4:
                phase = -((1.39621*mByM*mByM*(-40.9133 - 71.8844*mByM + 71.8844*mByM*mByM))/7.869754368);
                break;
        case 6:
                phase = (mByM*mByM*(25.711461 + 3.330852*mByM + 44.320444*mByM*mByM))/2.612736;
                break;                
        }
        return  phase;
}



static void UNUSED
XLALSimInspiralPNPhasingPrec_F2(
	PNPhasingSeries *pfa, /**< \todo UNDOCUMENTED */
	const REAL8 m1, /**< Mass of body 1, in Msol */
	const REAL8 m2, /**< Mass of body 2, in Msol */
	const REAL8 chi1L, /**< Component of dimensionless spin 1 along Lhat */
	const REAL8 chi2L, /**< Component of dimensionless spin 2 along Lhat */
	const REAL8 chi1sq,/**< Magnitude of dimensionless spin 1 */
	const REAL8 chi2sq, /**< Magnitude of dimensionless spin 2 */
	const REAL8 chi1dotchi2, /**< Dot product of dimensionles spin 1 and spin 2 */
	LALDict *p /**< LAL dictionary containing accessory parameters */
	)
{
    const REAL8 mtot = m1 + m2;
    const REAL8 eta = m1*m2/mtot/mtot;
    const REAL8 m1M = m1/mtot;
    const REAL8 m2M = m2/mtot;

    const REAL8 pfaN = 3.L/(128.L * eta);

    memset(pfa, 0, sizeof(PNPhasingSeries));

    pfa->v[0] = 1.L;
    pfa->v[1] = 0.L;
    pfa->v[2] = XLALSimInspiralTaylorF2Phasing_2PNCoeff(eta);
    pfa->v[3] = XLALSimInspiralTaylorF2Phasing_3PNCoeff(eta);
    pfa->v[4] = XLALSimInspiralTaylorF2Phasing_4PNCoeff(eta);
    pfa->v[5] = XLALSimInspiralTaylorF2Phasing_5PNCoeff(eta);
    pfa->vlogv[5] = XLALSimInspiralTaylorF2Phasing_5PNLogCoeff(eta);
    pfa->v[6] =  XLALSimInspiralTaylorF2Phasing_6PNCoeff(eta);
    pfa->vlogv[6] = XLALSimInspiralTaylorF2Phasing_6PNLogCoeff(eta);
    pfa->v[7] = XLALSimInspiralTaylorF2Phasing_7PNCoeff(eta);
    
    /* modify the PN coefficients if a non null LALSimInspiralTestGRParam structure is passed */
    /* BEWARE: this is for the non-spinning case only!*/
    pfa->v[0]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi0(p));
    pfa->v[1] = XLALSimInspiralWaveformParamsLookupNonGRDChi1(p);
    pfa->v[2]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi2(p));
    pfa->v[3]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi3(p));
    pfa->v[4]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi4(p));
    pfa->v[5]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi5(p));
    pfa->vlogv[5]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi5L(p));
    pfa->v[6]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi6(p));
    pfa->vlogv[6]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi6L(p));
    pfa->v[7]*=(1.0+XLALSimInspiralWaveformParamsLookupNonGRDChi7(p));

    const REAL8 qm_def1=1.+XLALSimInspiralWaveformParamsLookupdQuadMon1(p);
    const REAL8 qm_def2=1.+XLALSimInspiralWaveformParamsLookupdQuadMon2(p);

    switch( XLALSimInspiralWaveformParamsLookupPNSpinOrder(p) )
    {
        case LAL_SIM_INSPIRAL_SPIN_ORDER_ALL:
        case LAL_SIM_INSPIRAL_SPIN_ORDER_35PN:
	    pfa->v[7] += XLALSimInspiralTaylorF2Phasing_7PNSOCoeff(m1M)*chi1L+XLALSimInspiralTaylorF2Phasing_7PNSOCoeff(m2M)*chi2L;
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_SPIN_ORDER_3PN:
            pfa->v[6] += XLALSimInspiralTaylorF2Phasing_6PNSOCoeff(m1M)*chi1L
	      + XLALSimInspiralTaylorF2Phasing_6PNSOCoeff(m2M)*chi2L
	      + XLALSimInspiralTaylorF2Phasing_6PNS1S2OCoeff(eta)*chi1L*chi2L
	      + (XLALSimInspiralTaylorF2Phasing_6PNQM2SCoeff(m1M)*qm_def1+XLALSimInspiralTaylorF2Phasing_6PNSelf2SCoeff(m1M))*chi1L*chi1L
	      + (XLALSimInspiralTaylorF2Phasing_6PNQM2SCoeff(m2M)*qm_def2+XLALSimInspiralTaylorF2Phasing_6PNSelf2SCoeff(m2M))*chi2L*chi2L;
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_SPIN_ORDER_25PN:
            pfa->v[5] += XLALSimInspiralTaylorF2Phasing_5PNSOCoeff(m1M)*chi1L
	      + XLALSimInspiralTaylorF2Phasing_5PNSOCoeff(m2M)*chi2L;
            pfa->vlogv[5] += 3.*(XLALSimInspiralTaylorF2Phasing_5PNSOCoeff(m1M)*chi1L
				 + XLALSimInspiralTaylorF2Phasing_5PNSOCoeff(m2M)*chi2L);
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_SPIN_ORDER_2PN:
	    /* 2PN SS, QM, and self-spin */
            pfa->v[4] += XLALSimInspiralTaylorF2Phasing_4PNS1S2PrecCoeff(eta)*chi1dotchi2+XLALSimInspiralTaylorF2Phasing_4PNS1S2OPrecCoeff(eta)*chi1L*chi2L
	      + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecCoeff(m1M)*chi1L*chi1L + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecCoeff(m2M)*chi2L*chi2L
	      + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecCoeff(m1M)*chi1sq + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecCoeff(m2M)*chi2sq;
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_SPIN_ORDER_15PN:
            pfa->v[3] += XLALSimInspiralTaylorF2Phasing_3PNSOCoeff(m1M)*chi1L+XLALSimInspiralTaylorF2Phasing_3PNSOCoeff(m2M)*chi2L;
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_SPIN_ORDER_1PN:
        case LAL_SIM_INSPIRAL_SPIN_ORDER_05PN:
        case LAL_SIM_INSPIRAL_SPIN_ORDER_0PN:
            break;
        default:
            XLALPrintError("XLAL Error - %s: Invalid spin PN order %i\n",
			   __func__, XLALSimInspiralWaveformParamsLookupPNSpinOrder(p) );
            XLAL_ERROR_VOID(XLAL_EINVAL);
            break;
    }

    REAL8 lambda1=XLALSimInspiralWaveformParamsLookupTidalLambda1(p);
    REAL8 lambda2=XLALSimInspiralWaveformParamsLookupTidalLambda2(p);
    switch( XLALSimInspiralWaveformParamsLookupPNTidalOrder(p) )
    {
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_75PN:
            pfa->v[15] = (lambda1*XLALSimInspiralTaylorF2Phasing_15PNTidalCoeff(m1M) + lambda2*XLALSimInspiralTaylorF2Phasing_15PNTidalCoeff(m2M));
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_DEFAULT:
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_7PN:
            pfa->v[14] = (lambda1*XLALSimInspiralTaylorF2Phasing_14PNTidalCoeff(m1M) + lambda2*XLALSimInspiralTaylorF2Phasing_14PNTidalCoeff(m2M));
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_65PN:
            pfa->v[13] = (lambda1*XLALSimInspiralTaylorF2Phasing_13PNTidalCoeff(m1M) + lambda2*XLALSimInspiralTaylorF2Phasing_13PNTidalCoeff(m2M));
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_6PN:
            pfa->v[12] = (lambda1*XLALSimInspiralTaylorF2Phasing_12PNTidalCoeff(m1M) + lambda2*XLALSimInspiralTaylorF2Phasing_12PNTidalCoeff(m2M) );
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_5PN:
            pfa->v[10] = ( lambda1*XLALSimInspiralTaylorF2Phasing_10PNTidalCoeff(m1M) + lambda2*XLALSimInspiralTaylorF2Phasing_10PNTidalCoeff(m2M) );
#if __GNUC__ >= 7 && !defined __INTEL_COMPILER
            __attribute__ ((fallthrough));
#endif
        case LAL_SIM_INSPIRAL_TIDAL_ORDER_0PN:
            break;
        default:
            XLALPrintError("XLAL Error - %s: Invalid tidal PN order %i\n",
                           __func__, XLALSimInspiralWaveformParamsLookupPNTidalOrder(p) );
            XLAL_ERROR_VOID(XLAL_EINVAL);
    }


    /* At the very end, multiply everything in the series by pfaN */
    for(int ii = 0; ii <= PN_PHASING_SERIES_MAX_ORDER; ii++)
    {
        pfa->v[ii] *= pfaN;
        pfa->vlogv[ii] *= pfaN;
        pfa->vlogvsq[ii] *= pfaN;
    }
}

static INT4 UNUSED
PrecInducedCircular2PNPhasing_F2(
        const REAL8 m1, 
        const REAL8 m2, 
        const REAL8 chi1L, /**< Component of dimensionless spin 1 along Lhat */
	const REAL8 chi2L, /**< Component of dimensionless spin 2 along Lhat */
	const REAL8 chi1sq,/**< Magnitude of dimensionless spin 1 */
	const REAL8 chi2sq, /**< Magnitude of dimensionless spin 2 */
	const REAL8 chi1dotchi2 /**< Dot product of dimensionles spin 1 and spin 2 */
        )
{
  const REAL8 mtot = m1 + m2;
  const REAL8 eta = m1*m2/mtot/mtot;
  const REAL8 m1M = m1/mtot;
  const REAL8 m2M = m2/mtot;
  
  INT4 PrecIndCircPNCoeffs = 0;
  const REAL8 global_fac = 3.L/(128.L * eta);
 
  PrecIndCircPNCoeffs = XLALSimInspiralTaylorF2Phasing_4PNS1S2OPrecIndCircCoeff(eta)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_4PNS1S2PrecIndCircCoeff(eta)*chi1dotchi2
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecIndCircCoeff(m1M)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecIndCircCoeff(m2M)*chi2L*chi2L + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecIndCircCoeff(m1M)*chi1sq
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecIndCircCoeff(m2M)*chi2sq; 

  return global_fac * PrecIndCircPNCoeffs;
}


static INT4 UNUSED
PrecEccentricityPNCoeffs_F2(
        const REAL8 m1, 
        const REAL8 m2, 
        const REAL8 chi1L, /**< Component of dimensionless spin 1 along Lhat */
	const REAL8 chi2L, /**< Component of dimensionless spin 2 along Lhat */
	const REAL8 chi1sq,/**< Magnitude of dimensionless spin 1 */
	const REAL8 chi2sq, /**< Magnitude of dimensionless spin 2 */
	const REAL8 chi1dotchi2, /**< Dot product of dimensionles spin 1 and spin 2 */
        REAL8 PrecEccPNCoeffs[LAL_MAX_ECC_PN_ORDER+1][LAL_MAX_ECC_PN_ORDER+1][LAL_MAX_ECC_PN_ORDER+1]
        )
{
  const REAL8 mtot = m1 + m2;
  const REAL8 eta = m1*m2/mtot/mtot;
  const REAL8 m1M = m1/mtot;
  const REAL8 m2M = m2/mtot;
  
  INT4 ret = 0;
  memset(PrecEccPNCoeffs, 0x00, (LAL_MAX_ECC_PN_ORDER+1)*(LAL_MAX_ECC_PN_ORDER+1)*(LAL_MAX_ECC_PN_ORDER+1)*sizeof(REAL8));
  PrecEccPNCoeffs[0][0][0] = 0.0; // lowest order constant term

  PrecEccPNCoeffs[2][2][0] = 0.0; //v^2 term
  PrecEccPNCoeffs[2][1][1] = 0.0; //v*v0 term
  PrecEccPNCoeffs[2][0][2] = 0.0; //v0^2 term

  PrecEccPNCoeffs[3][3][0] = XLALSimInspiralTaylorF2Phasing_3PNSOEccCoeff(m1M, 0)*chi1L + XLALSimInspiralTaylorF2Phasing_3PNSOEccCoeff(m2M, 0)*chi2L; //v^3 term
  PrecEccPNCoeffs[3][0][3] = XLALSimInspiralTaylorF2Phasing_3PNSOEccCoeff(m1M, 3)*chi1L + XLALSimInspiralTaylorF2Phasing_3PNSOEccCoeff(m2M, 3)*chi2L; //v0^3 term

  PrecEccPNCoeffs[4][4][0] = XLALSimInspiralTaylorF2Phasing_4PNS1S2OPrecEccCoeff(eta, 0)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_4PNS1S2PrecEccCoeff(eta, 0)*chi1dotchi2
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecEccCoeff(m1M, 0)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecEccCoeff(m2M, 0)*chi2L*chi2L + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecEccCoeff(m1M, 0)*chi1sq
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecEccCoeff(m2M, 0)*chi2sq; //v^4 term
  PrecEccPNCoeffs[4][2][2] = 0.0; //v^2*v0^2 term
  PrecEccPNCoeffs[4][0][4] = XLALSimInspiralTaylorF2Phasing_4PNS1S2OPrecEccCoeff(eta, 4)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_4PNS1S2PrecEccCoeff(eta, 4)*chi1dotchi2
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecEccCoeff(m1M, 4)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SOPrecEccCoeff(m2M, 4)*chi2L*chi2L + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecEccCoeff(m1M, 4)*chi1sq
                         + XLALSimInspiralTaylorF2Phasing_4PNSelf2SPrecEccCoeff(m2M, 4)*chi2sq;  //v0^4 term

  PrecEccPNCoeffs[5][5][0] = XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m1M, 0)*chi1L + XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m2M, 0)*chi2L; //v^5 term
  PrecEccPNCoeffs[5][3][2] = XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m1M, 2)*chi1L + XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m2M, 2)*chi2L; //v^3*v0^2 term
  PrecEccPNCoeffs[5][2][3] = XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m1M, 3)*chi1L + XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m2M, 3)*chi2L; //v^2*v0^3 term
  PrecEccPNCoeffs[5][0][5] = XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m1M, 5)*chi1L + XLALSimInspiralTaylorF2Phasing_5PNSOEccCoeff(m2M, 5)*chi2L;  //v0^5 term

  PrecEccPNCoeffs[6][6][0] = XLALSimInspiralTaylorF2Phasing_6PNSOEccCoeff(m1M, 0)*chi1L + XLALSimInspiralTaylorF2Phasing_6PNSOEccCoeff(m2M, 0)*chi2L 
                         + XLALSimInspiralTaylorF2Phasing_6PNS1S2OEccCoeff(eta, 0)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m1M, 0)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m2M, 0)*chi2L*chi2L; //v^6 term except log(16*v^2) term
  PrecEccPNCoeffs[6][4][2] = XLALSimInspiralTaylorF2Phasing_6PNS1S2OEccCoeff(eta, 2)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m1M, 2)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m2M, 2)*chi2L*chi2L; //v^4*v0^2 term
  PrecEccPNCoeffs[6][3][3] = XLALSimInspiralTaylorF2Phasing_6PNSOEccCoeff(m1M, 3)*chi1L + XLALSimInspiralTaylorF2Phasing_6PNSOEccCoeff(m2M, 3)*chi2L 
                         + XLALSimInspiralTaylorF2Phasing_6PNS1S2OEccCoeff(eta, 3)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m1M, 3)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m2M, 3)*chi2L*chi2L; //v^3*v0^3 term
  PrecEccPNCoeffs[6][2][4] = XLALSimInspiralTaylorF2Phasing_6PNS1S2OEccCoeff(eta, 4)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m1M, 4)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m2M, 4)*chi2L*chi2L; //v^2*v0^4 term
  PrecEccPNCoeffs[6][0][6] = XLALSimInspiralTaylorF2Phasing_6PNSOEccCoeff(m1M, 6)*chi1L + XLALSimInspiralTaylorF2Phasing_6PNSOEccCoeff(m2M, 6)*chi2L 
                         + XLALSimInspiralTaylorF2Phasing_6PNS1S2OEccCoeff(eta, 6)*chi1L*chi2L + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m1M, 6)*chi1L*chi1L
                         + XLALSimInspiralTaylorF2Phasing_6PNSelf2SEccCoeff(m2M, 6)*chi2L*chi2L;  //v0^6 term except log(16*v0^2) term
  //printSpinPNCoeffs_F2(SpinEccPNCoeffs);
  return ret;
}

static REAL8 UNUSED
PrecEccentricityPhasing_F2(REAL8 v, REAL8 v0, REAL8 ecc, REAL8 m1, REAL8 m2, REAL8 chi1L, REAL8 chi2L, REAL8 chi1sq, REAL8 chi2sq, REAL8 chi1dotchi2, INT4 ecc_order)
{
  static REAL8 v0_power[LAL_MAX_ECC_PN_ORDER+1];
  /* following code is not efficient in memory usage, need to be improved later */
  static REAL8 PrecEccPNCoeffs[LAL_MAX_ECC_PN_ORDER+1][LAL_MAX_ECC_PN_ORDER+1][LAL_MAX_ECC_PN_ORDER+1]; // we want to calculate just one time
  REAL8 v_power[LAL_MAX_ECC_PN_ORDER+1];
  REAL8 phasing = 0.0;
  REAL8 global_factor;
  REAL8 eta= (m1*m2)/((m1+m2)*(m1+m2));
  //REAL8 chi1sq = chi1L*chi1L;
  //REAL8 chi2sq = chi2L*chi2L; 
  v0_power[0] = 1.0;
  for(int i=1; i<=LAL_MAX_ECC_PN_ORDER; i++)
  {
    v0_power[i] = v0_power[i-1]*v0;
  }
  PrecEccentricityPNCoeffs_F2(m1, m2, chi1L, chi2L, chi1sq, chi2sq, chi1dotchi2, PrecEccPNCoeffs);
  //printPNCoeffs_F2(SpinEccPNCoeffs);
  v_power[0] = 1.0;
  for(int i=1; i<=LAL_MAX_ECC_PN_ORDER; i++)
  {
    v_power[i] = v_power[i-1]*v;
  }

  global_factor = -2.355/1.462*ecc*ecc*pow(v0/v, 19.0/3.0);
  global_factor *= (3.0/128.0/eta);  // overall factor except v^-5 in phase term, this is Newtonian phase term

  
  if(ecc_order == -1) {
    ecc_order = LAL_MAX_ECC_PN_ORDER;
  }
  if(ecc_order > LAL_MAX_ECC_PN_ORDER) {
    return XLAL_REAL8_FAIL_NAN;
  }

  REAL8 PrecPhaseOrder = 0;
  for(int i=0; i<=ecc_order; i++)
  {
    PrecPhaseOrder = 0;
    INT4 k = 0;
    for(int j=i; j>=0; j--)
    {
      k = i - j;
      PrecPhaseOrder += PrecEccPNCoeffs[i][j][k]*v_power[j]*v0_power[k];
    }
    phasing += PrecPhaseOrder;
      //ecc_phase_order[i] = SpinPhaseOrder*global_factor;
  }
  
  REAL8 PrecIndCircTerm = PrecInducedCircular2PNPhasing_F2(m1, m2, chi1L, chi2L, chi1sq, chi2sq, chi1dotchi2) * pow(v0/v, 31.0/3.0) * v * v;
  //fprintf(stdout, "======== DEBUG for eccentricity ================\n");
  //fprintf(stdout, "eccentricityPhasing_F2 phasing = %g, global_factor = %g, ecc_order = %d, ecc = %g\n", phasing, global_factor, ecc_order, ecc);
  return phasing*global_factor + PrecIndCircTerm;
}
