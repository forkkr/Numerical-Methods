import numpy as np
import matplotlib.pyplot as mpl


class CurrentState:
    def __init__(self , x_n , x_p , x_m , f_xm ,err):
        self.x_n = x_n
        self.x_p = x_p
        self.x_m = x_m
        self.f_xm = f_xm
        self.err = err


class FalsePositionMethod:
    def __init__(self, x0, x1):
        if FalsePositionMethod.getfunctionvalue(x0) < 0:
            self.negativePoint = x0
            self.positivePoint = x1
        else:
            self.positivePoint = x0
            self.negativePoint = x1
        self.myold = None

    @staticmethod
    def getfunctionvalue( x ):
        return (x*x*x) - 0.165*(x*x) + 3.993*1e-4

    @staticmethod
    def finderror(new , old):
        if old is None:
            return None
        return 100*abs(new - old)/old

    def getnewpoint(self):
        xm = ((-1)*FalsePositionMethod.getfunctionvalue(self.positivePoint)*(self.positivePoint-self.negativePoint))/(FalsePositionMethod.getfunctionvalue(self.positivePoint) - FalsePositionMethod.getfunctionvalue(self.negativePoint)) + self.positivePoint;
        return xm

    def run(self):
        xm = FalsePositionMethod.getnewpoint(self)
        f_x = FalsePositionMethod.getfunctionvalue(xm)
        if f_x < 0:
            self.negativePoint = xm
        else:
            self.positivePoint = xm
        err = FalsePositionMethod.finderror(xm, self.myold)
        self.myold = xm
        st = CurrentState(self.negativePoint, self.positivePoint, xm , f_x , err)
        return st


xm, err, fxm = [], [], []
fpm = FalsePositionMethod(float(input('Enter X1: ')), float(input('Enter X2: ')))
iteration = int(input('Iterations: '))
for i in range(iteration):
    st = fpm.run()
    print(i+1, st.x_n, st.x_p, st.x_m, st.f_xm)
    xm.append(st.x_m)
    err.append(st.err)
    fxm.append(st.f_xm)


mpl.plot(xm)
mpl.ylabel('X mid')
mpl.xlabel('Iterations')
mpl.show()
mpl.ylabel('Error')
mpl.xlabel('Iterations')
mpl.plot(err)
mpl.show()
mpl.ylabel('F(X mid)')
mpl.xlabel('X mid')

ax1 = mpl.subplot()

ax1.set_ylim(-.0005,.0005)
ax1.set_xlim(0.05,.09)
mpl.scatter(xm,fxm)
mpl.show()