from urllib import request
import numpy as np
import os

__all__ = ['NearestNeighbor', 'load_cifar10', 'validate_shapes']


class NearestNeighbor(object):
    def __init__(self):
        pass
    
    def train(self, X, y):
        """ X is N x D where each row is an example. Y is 1-dimension of size N """
        # the nearest neighbor classifier simply remembers all the training data
        self.Xtr = X
        self.ytr = y
    
    def compute_distances(self, X):
        """ Write a function that computes the L2 distance between each sample in X
            and every training example
            Parameters
            ----------
            X : numpy.ndarray
            X.shape must be (M, N) where M, N > 0
            Each row of X is a flattened vector representing a single image
            Returns
            -------
            distances : numpy.ndarray
            distances.shape = (len(X), len(self.Xtr))
            distances[i, j] = the L2 distance between X[i] and self.Xtr[j]
            """
        #print(X.shape, self.Xtr.shape)
        dists = np.zeros((X.shape[0], self.Xtr.shape[0]))
        for i in range(X.shape[0]):
            X_r = np.tile(X[i], (self.Xtr.shape[0], 1))
            dists[i] = np.sqrt(np.sum(np.square(self.Xtr - X_r), axis = 1))
        #print(dists.shape)
        return dists
    
    def predict(self, dists, k=1):
        """ Given a matrix of distances between test points and training points,
            predict a label for each test point.
            Parameters
            ----------
            dists : numpy.ndarray
            dists.shape must be (N x len(self.Xtr)) where N is the number of
            examples you wish to predict labels for
            Returns
            -------
            y_pred : numpy.array
            A numpy array of shape (N,) containing predicted labels for
            every sample represented in dists
            """
        s = np.argsort(dists, axis=1)
        y_pred = np.zeros(dists.shape[0])
        for i in range(dists.shape[0]):
            y_pred[i] = np.argmax(np.bincount(self.ytr[s[i,:k]]))
        return y_pred


def load_cifar10(fname='cifar-10-python.npz'):
    url = 'https://www.dropbox.com/s/8ytbmlvy2au72lc/cifar-10-python.npz?dl=0'
    if not os.path.exists(fname):
        msg = '\n\n'.join(["Data not found! Please download the data (cifar-10-python.npz) from here:",
                           url,
                           "and place the file in this directory!"])
        raise FileNotFoundError(msg)
    with np.load(fname) as data:
        return tuple(data[key] for key in ['x_train', 'y_train', 'x_test', 'y_test'])


def validate_shapes(x_train_fold, y_train_fold, x_val_fold, y_val_fold):
    xt_shape, yt_shape = x_train_fold.shape, y_train_fold.shape
    xv_shape, yv_shape = x_val_fold.shape, y_val_fold.shape
    assert(xt_shape[0] == yt_shape[0]), "Error: different number of training images and labels"
    assert(xv_shape[0] == yv_shape[0]), "Error: different number of validation images and labels"
    assert(xv_shape[1] == xt_shape[1]), "Error: training and validation images are different sizes"
    assert(len(yt_shape) == 1 or min(yt_shape) < 2), "Error: training labels have improper dimensions"
    assert(len(yv_shape) == 1 or min(yv_shape) < 2), "Error: validation labels have improper dimensions"
    if len(yt_shape) > 1 and min(yt_shape) == 1:
        print("Warning: training labels have shape (N, 1) or (1, N) when they should have (N,)")
    if len(yv_shape) > 1 and min(yv_shape) == 1:
        print("Warning: validation labels have shape (N, 1) or (1, N) when they should have (N,)")
